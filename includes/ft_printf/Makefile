CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_uputnbr_fd.c ft_puthex_fd.c ft_putptr_fd.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
