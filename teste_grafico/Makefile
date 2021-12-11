# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:57:06 by fmoreira          #+#    #+#              #
#    Updated: 2021/12/11 15:30:18 by fmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS= -Imlx -g -Wall -Wextra -Werror

NAME=fractol

SRC = $(shell find -name '*.c' | grep "srcs")
OBJ = $(SRC:%.c=%.o)

LFLAGS = -Lmlx -lmlx -lXext -lX11  -lm -g -Wall -Wextra -Werror

all: $(NAME)

$(MAKE_ALL):
		make -C libft
		make -C mlx

$(NAME):	${OBJ} ${MAKE_ALL}
		$(MAKE_ALL)
		$(CC) -o $(NAME) ${OBJ} $(LFLAGS)



clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
