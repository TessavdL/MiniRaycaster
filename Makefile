# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tevan-de <tevan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/07 10:51:44 by tevan-de      #+#    #+#                  #
#    Updated: 2022/08/08 14:52:19 by tevan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			:=	cub3D

CC				:=	gcc

CFLAGS			:=	-Wall -Wextra -Werror

LDFLAGS			:=

MLXFLAGS		:=	-framework OpenGL -framework AppKit -O3 

CFILES			:=	colors.c				\
					cub3d.c					\
					cub3d_utils.c			\
					draw_3d_ray.c			\
					main.c					\
					mlx_events.c			\
					mlx_functions.c			\
					movement.c				\
					parser.c				\
					parser_error_check.c	\
					parser_map.c			\
					parser_map_floodfill.c	\
					parser_utils.c			\
					parser_utils2.c			\
					parser_utils3.c			\
					parser_utils4.c			\
					raycasting.c

BONUSCFILES		:=	bmp_bonus.c						\
					colors_bonus.c					\
					cub3d_bonus.c					\
					cub3d_utils_bonus.c				\
					draw_3d_ray_bonus.c				\
					draw_floor_bonus.c				\
					draw_minimap_bonus.c			\
					main_bonus.c					\
					mlx_events_bonus.c				\
					mlx_functions_bonus.c			\
					movement_bonus.c 				\
					parser_error_check_bonus.c 		\
					parser_map_floodfill_bonus.c	\
					parser_map_bonus.c				\
					parser_utils_bonus.c			\
					parser_utils2_bonus.c			\
					parser_utils3_bonus.c			\
					parser_utils4_bonus.c			\
					parser_bonus.c					\
					raycasting_bonus.c				\
					sprites_bonus.c

OBJS_DIR		=	objs/

EXT_LIB			=	./libft/libft.a 					\
					./get_next_line/libget_next_line.a	\
					./libmlx.dylib

INCLUDES		=	./libft/libft.h					\
					./get_next_line/get_next_line.h	\
					./mlx_macos/mlx.h

ifndef BONUS
SRCS_DIR		=	srcs/
OBJS			=	$(CFILES:%.c=$(OBJS_DIR)%.o)
INCLUDES 		+=	./includes/cub3d.h
endif

ifdef BONUS
SRCS_DIR		=	srcs_bonus/
OBJS			=	$(BONUSCFILES:%.c=$(OBJS_DIR)%.o)
INCLUDES 		+=	./includes_bonus/cub3d_bonus.h
endif

ifdef DEBUG
LDFLAGS 		+=	-g -fsanitize=address
endif

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus:
	@$(MAKE) BONUS=1 all

$(NAME): $(OBJS) $(EXT_LIB)
	@$(CC) $(LDFLAGS) $^ -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXT_LIB):
	@make bonus -C ./libft/
	@make -C ./mlx_macos/
	@make -C ./get_next_line/

clean:
	@rm -rf $(OBJS_DIR)*.o
	@echo "Cleaned object files"
	@make clean -C ./libft/
	@make clean -C ./get_next_line/

fclean: clean
	@rm -rf $(NAME)
	@rm -rf screenshot.bmp
	@echo "Cleaned executeable"
	@make fclean -C ./libft/
	@make fclean -C ./get_next_line/
	@make clean -C ./mlx_macos

re: fclean all
