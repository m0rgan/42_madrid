CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_printf.c \
		ft_printf_puts.c
NAME = libftprintf.a

$(NAME): $(SOURCE:.c=.o)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all

clean:
	@rm -f $(SOURCE:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all

all: $(NAME)