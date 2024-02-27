CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_pipex.c waits.c
NAME = pipex

$(NAME): $(SOURCE:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all

clean:
	@rm -f $(SOURCE:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all

all: $(NAME)