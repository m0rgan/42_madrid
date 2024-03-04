CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY = mandatory/ft_pipex.c
BONUS = bonus/ft_pipex_bonus.c \
		bonus/execution.c \
		bonus/files_management.c \
		bonus/parse_argv.c
UTILS = utils/ft_find_path.c \
        utils/ft_get_cmd.c \
		utils/ft_split_command.c
SOURCE = $(MANDATORY) $(UTILS)
SOURCE_BONUS = $(BONUS) $(UTILS)
LIBFT = libft/libft.a
NAME = pipex

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(SOURCE:.c=.o) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L. -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all

clean:
	@rm -f $(SOURCE:.c=.o)

fclean: clean
	@rm -f $(NAME) $(LIBFT)

re: fclean all

all: $(NAME)

bonus: $(SOURCE_BONUS:.c=.o) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L. -lft -o pipex_bonus