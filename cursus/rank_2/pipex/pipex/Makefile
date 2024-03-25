BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
RESET=\033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY = mandatory/ft_pipex.c
BONUS = bonus/ft_pipex_bonus.c \
		bonus/execution_bonus.c \
		bonus/files_manage_bonus.c \
		bonus/parse_argv_bonus.c \
		bonus/wait_pids_bonus.c
UTILS = utils/ft_find_path.c \
		utils/ft_free.c \
        utils/ft_get_cmd.c \
		utils/ft_split_command.c \
		utils/ft_write_error.c
GNL = gnl/get_next_line.c \
		gnl/get_next_line_utils.c
SRC = $(MANDATORY) $(UTILS)
SRC_BONUS = $(BONUS) $(UTILS) $(GNL)
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
INCLS = -Iincludes
NAME = pipex

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(BLUE)<----compiling libft---->$(RESET)"
	@(cd ./libft && make)
	@echo "$(GREEN)<----libft compiled!---->$(RESET)"
	@echo "$(YELLOW)****/compiling pipex\****$(RESET)"
	@$(CC) $(OBJS) -L./libft -lft -o $(NAME)
	@echo "$(GREEN)****\pipex compiled!/****$(RESET)"

all: $(NAME)

clean:
	@(cd ./libft && make clean)
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "$(RED)--->objects deleted<----$(RESET)"

fclean: clean
	@(cd ./libft && make fclean)
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@echo "$(RED)---->pipex deleted<----$(RESET)"

re: fclean all

bonus:
	@make SRC='$(SRC_BONUS)'

.PHONY: all clean fclean re bonus
