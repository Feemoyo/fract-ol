CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf
MLXFLAGS = -lX11 -lXext -lm -lz
LIBSMK = make -C
NAME = fractol

SRC_DIR = srcs
#$(shell find -name '*.c' | grep "srcs" | cut -c 8-)
SRC = ft_colouring_01.c ft_couloring_02.c ft_data.c ft_draw_01.c ft_draw_02.c ft_events_01.c ft_events_02.c \
	ft_julia.c ft_mandelbrot.c ft_parsing.c ft_utils.c ft_zoom.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDED = ./includes
INCLUDE = fractol.h
LIBFTD = ./libs/libft
MLXD = ./libs/mlx

MAIN = srcs/main.c

LIBFT = ./libs/libft/libft.a
MLX =	./libs/mlx/libmlx.a

all:	$(NAME)

$(NAME):	$(LIBS) $(OBJ)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBS):
	$(LIBSMK) $(LIBFTD) all
	$(LIBSMK) $(MLXD) all

clean:
	$(RM) $(OBJ_DIR)
	$(LIBSMK) $(LIBFTD) clean
	$(LIBSMK) $(MLXD) clean

fclean: clean
	$(LIBSMK) $(LIBFTD) fclean
	$(LIBSMK) $(MLXD) fclean

re:	fclean all

.PHONY: re all clean fclean