CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = src/so_long.c src/utils.c src/utils_2.c src/utils_3.c includes/getnextline/get_next_line.c includes/getnextline/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
NAME = so_long

LIBFTPRINTF = includes/ft_printf/libftprintf.a
INCLUDES = -I/opt/X11/include -Iincludes/ft_printf
MLX = includes/mlx/libmlx.a
MLX_FLAGS = -Lincludes/mlx -lmlx -L/usr/X11/lib -lXext -lX11

all: $(NAME)

$(LIBFTPRINTF):
	@make -C includes/ft_printf

$(MLX):
	@make -C includes/mlx

$(NAME): $(LIBFTPRINTF) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFTPRINTF) $(MLX) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -f $(OBJ)
	@make -C includes/ft_printf clean
	@make -C includes/mlx clean || true

fclean: clean
	@rm -f $(NAME)
	@make -C includes/ft_printf fclean
	@make -C includes/mlx fclean || true

re: fclean all

.PHONY: all clean fclean re
