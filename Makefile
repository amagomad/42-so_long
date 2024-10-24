CC = clang
CFLAGS = -Wall -Wextra -Werror -g
SRC = src/so_long.c src/utils.c src/map/map.c src/map/draw_characters.c src/map/map_parsing.c src/map/map_parsing_2.c src/free.c src/fd.c includes/getnextline/get_next_line.c includes/getnextline/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
NAME = so_long

LIBFTPRINTF = includes/ft_printf/libftprintf.a
INCLUDES = -I/opt/X11/include -Iincludes/ft_printf
MLX = includes/minilibx-linux/libmlx.a
MLX_FLAGS = -Lincludes/minilibx-linux -lmlx -L/usr/X11/lib -lXext -lX11

all: $(NAME)

$(LIBFTPRINTF):
	@make -C includes/ft_printf

$(MLX):
	@make -C includes/minilibx-linux

$(NAME): $(LIBFTPRINTF) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFTPRINTF) $(MLX) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -f $(OBJ)
	@make -C includes/ft_printf clean
	@make -C includes/minilibx-linux clean || true

fclean: clean
	@rm -f $(NAME)
	@make -C includes/ft_printf fclean
	@make -C includes/minilibx-linux fclean || true

re: fclean all

.PHONY: all clean fclean re
