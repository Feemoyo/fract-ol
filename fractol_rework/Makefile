CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf
MLXFLAGS = -lX11 -lXext -lm -lz
LIBSMK = make -C

SRC_DIR = srcs
SRC = $(shell find -name '*.c' | grep "srcs" | cut -c 8-)

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDE_DIR = ./includes
INCLUDE = fractol.h

MAIN = srcs/main.c

LIBFT = ./libs/libft.a
MLX =	./libs/milibx_Linux.a
LIBS := ${LIBFT} ${MLX}

all:	${NAME}

${NAME}:	${LIBS} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${MLXFLAGS} ${LIBS} -o ${NAME}

${OBJ_DIR}%.o: %.c
	mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@

$(LIBS):
	$(LIBSMK) $(LIBFT)
	$(LIBSMK) $(MLX)

clean:
	${RM} ${OBJ_DIR}
	${LIBSMK} ${LIBFT} clean
	${LIBSMK} ${MLX} clean

fclea: clean
	${RM} ${LIBFT} fclean
	${RM} ${MLX} fclean

re:	fclean all
.PHONY: re all clean fclean