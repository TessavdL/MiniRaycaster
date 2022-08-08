# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tevan-de <tevan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/10 11:40:24 by tevan-de      #+#    #+#                  #
#    Updated: 2022/02/16 14:51:54 by tevan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

CFILES		=	ft_atoi.c				\
				ft_bzero.c				\
				ft_calloc.c				\
				ft_isalnum.c			\
				ft_isalpha.c			\
				ft_isascii.c			\
				ft_isdigit.c			\
				ft_isprint.c			\
				ft_itoa.c				\
				ft_memccpy.c			\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_memcpy.c				\
				ft_memmove.c			\
				ft_memset.c				\
				ft_putchar_fd.c			\
				ft_putstr_fd.c			\
				ft_putendl_fd.c			\
				ft_putnbr_fd.c			\
				ft_split.c				\
				ft_strchr.c				\
				ft_strdup.c				\
				ft_strjoin.c			\
				ft_strlcat.c			\
				ft_strlcpy.c			\
				ft_strlen.c				\
				ft_strmapi.c			\
				ft_strncmp.c			\
				ft_strnstr.c			\
				ft_strrchr.c			\
				ft_strtrim.c			\
				ft_substr.c				\
				ft_toupper.c			\
				ft_tolower.c

BONUSCFILES	=	ft_lstnew_bonus.c		\
				ft_lstadd_front_bonus.c	\
				ft_lstsize_bonus.c		\
				ft_lstlast_bonus.c		\
				ft_lstadd_back_bonus.c	\
				ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c		\
				ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c

OFILES		=	${CFILES:%.c=%.o}

BONUSOFILES	=	${BONUSCFILES:%.c=%.o}

HEADERFILES	=	libft.h

ifdef BONUS
OFILES 		+=	$(BONUSOFILES)
endif

.PHONY: all clean fclean re

all: $(NAME)

bonus:
	@$(MAKE) BONUS=1 all

$(NAME): $(OFILES)
	@ar -rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "Created $(NAME)"

%.o: %.c $(HEADERFILES)
	@echo "Compiling: $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "Cleaning all object files"
	@/bin/rm -f $(OFILES) $(BONUSOFILES)

fclean: clean
	@echo "Cleaning $(NAME)"
	@/bin/rm -f $(NAME)

re:	fclean all
