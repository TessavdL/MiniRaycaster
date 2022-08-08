# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tevan-de <tevan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/10 11:40:24 by tevan-de      #+#    #+#                  #
#    Updated: 2021/06/11 11:41:48 by tevan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libget_next_line.a

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

CFILES		=	get_next_line.c			\
				get_next_line_utils.c

OFILES		=	${CFILES:%.c=%.o}

HEADERFILES	=	./get_next_line.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	@ar -rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "Created $(NAME)"

%.o: %.c $(HEADERFILES)
	@echo "Compiling: $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "Cleaning all object files"
	@/bin/rm -f $(OFILES)

fclean: clean
	@echo "Cleaning $(NAME)"
	@/bin/rm -f $(NAME)

re:	fclean all
