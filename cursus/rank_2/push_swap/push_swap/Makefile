CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_printf.c \
		ft_printf_utils.c
NAME = push_swap

$(NAME): $(SOURCE:.c=.o)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all bonus

clean:
	@rm -f $(SOURCE:.c=.o) $(BONUS:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all

all: $(NAME)