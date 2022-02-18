# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:57:06 by fmoreira          #+#    #+#              #
#    Updated: 2022/02/18 19:25:41 by fmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS= -Wall -Wextra -Werror
RM = rm -rf

NAME = fractol

SRC = $(shell find -name '*.c' | grep "srcs" | cur -c 8-)
OBJ = $(SRC:%.c=%.o)

LIBLAGS = -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME):	${OBJ}
		@make -C libs/libft
		@make -C libs/mlx
		@$(CC) -o $(NAME) ${OBJ} $(LIBFLAGS) $(CFLAGS) libs/mlx/libmlx_Linux.a libs/libft/libft.a

clean:
		@$(RM) $(OBJ)
		@make clean -C libs/libft
		@make clean -C libs/mlx

fclean:	clean
		@$(RM) $(NAME)
		@make fclean -C libs/libft
		@make clean -C libs/mlx

re:	fclean all
