# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:57:06 by fmoreira          #+#    #+#              #
#    Updated: 2021/12/10 23:11:37 by fmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

SRC_DIR		= srcs

SRCS		= main.c init.c julia.c color.c

SRC		= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ			= $(SRCS:.c=.o)

CFLAGS		= gcc -Wall -Werror -Wextra
LIBFLAGS	= -L libft -lft
MLXFLAGS	= -L mlx -lmlx -framework AppKit -framework OpenGL
INCLUDES	= -I includes -I libft -I mlx

all		: $(NAME)

$(NAME):
		@printf "Compiling...\n"
		@cd ./libft ; @make all ; cd ..
		@cd ./mlx ; @make all ; cd ..
		@$(CFLAGS) $(INCLUDES) -c $(SRC)
		@$(CFLAGS) $(OBJ) $(LIBFLAGS) $(MLXFLAGS) $(INCLUDES) -o $(NAME)
		@printf "Complete!"

clean:
		@rm -rf ${OBJ}
		cd ./libft ; @make clean ; cd ..
		cd ./mlx ; @make clean ; cd ..

fclean:	clean
		@rm -f $(NAME)

re:		flcean all

.PHONY:		all fclean clean re
