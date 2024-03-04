CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_memcpy.c \
		ft_pipex_utils.c \
		ft_pipex.c \
		ft_realloc.c \
		ft_split_command.c \
		ft_split.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strndup.c \
		ft_strnlen.c \
		ft_substr.c
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