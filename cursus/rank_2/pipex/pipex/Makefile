CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_pipex.c
NAME = pipex

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