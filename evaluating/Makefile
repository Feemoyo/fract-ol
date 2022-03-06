CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -o3

RM = rm -rf
MLXFLAGS = -lX11 -lXext -lm -lz
LIBSMK = make -C
NAME = fractol

SRC_DIR = srcs
#$(shell find -name '*.c' | grep "srcs" | cut -c 8-)
SRC = ft_colouring_01.c ft_colouring_02.c ft_data.c ft_draw_01.c ft_draw_02.c ft_events.c \
	ft_julia.c ft_mandelbrot.c ft_parsing.c ft_utils.c ft_zoom.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDED = ./includes
INCLUDE = fractol.h

MAIN = srcs/main.c

LIBFTD = ./libs/libft/
MLXD = ./libs/mlx/

LIBFT = ./libs/libft/libft.a
MLX =	./libs/mlx/libmlx.a

vpath %.c $(SRC_DIR)
vpath %.h $(INCD_DIR)

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(LIBSMK) $(LIBFTD)

$(MLX):
	$(LIBSMK) $(MLXD)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(LIBSMK) $(LIBFTD) clean

fclean: clean
	$(RM) $(NAME)
	$(LIBSMK) $(LIBFTD) fclean
	$(LIBSMK) $(MLXD) clean

re:	fclean all

.PHONY: re all clean fclean