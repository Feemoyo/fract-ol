# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:57:06 by fmoreira          #+#    #+#              #
#    Updated: 2022/01/17 06:47:00 by fmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS= -Imlx -g -Wall -Wextra -Werror

NAME=fractol

SRC = $(shell find -name '*.c' | grep "srcs")
OBJ = $(SRC:%.c=%.o)

LFLAGS = -Lmlx -lmlx -lXext -lX11  -lm -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	${OBJ}
		make -C libft
		make -C mlx
		$(CC) -o $(NAME) ${OBJ} $(LFLAGS) libs/mlx/libmlx.a libs/libft/libft.a

clean:
		rm -f $(OBJ)
		make clean -C libft
		make clean -C mlx

fclean:	clean
		rm -f $(NAME)
		make fclean -C libft
		make clean -C mlx

re:	fclean all
