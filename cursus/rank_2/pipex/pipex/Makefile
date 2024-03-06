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
		bonus/parse_argv_bonus.c
UTILS = utils/ft_find_path.c \
		utils/ft_free.c \
        utils/ft_get_cmd.c \
		utils/ft_no_envp.c \
		utils/ft_split_command.c
SOURCE = $(MANDATORY) $(UTILS)
SOURCE_BONUS = $(BONUS) $(UTILS)
OBJS = $(SOURCE:.c=.o)
OBJS_BONUS = $(SOURCE_BONUS:.c=.o)
INCLS = -Iincludes
NAME = pipex
NAME_B = pipex_bonus

%.o: %.c
	@${CC} ${CFLAGS} ${INCLS} -c $< -o $@

${NAME}: ${OBJS}
	@echo "$(BLUE)<----compiling libft---->$(RESET)"
	@(cd ./libft && make re > /dev/null 2>&1)
	@echo "$(GREEN)<----libft compiled!---->$(RESET)"
	@echo "$(YELLOW)****/compiling pipex\****$(RESET)"
	@$(CC) ${OBJS} -L./libft -lft -o ${NAME}
	@echo "$(GREEN)****\pipex compiled!/****$(RESET)"

${NAME_B}: ${OBJS_BONUS}
	@echo "$(BLUE)<----compiling libft---->$(RESET)"
	@(cd ./libft && make re > /dev/null 2>&1)
	@echo "$(GREEN)<----libft compiled!---->$(RESET)"
	@echo "$(YELLOW)****/compiling pipex bonus\****$(RESET)"
	@$(CC) ${OBJS_BONUS} -L./libft -lft -o ${NAME_B}
	@echo "$(GREEN)****\pipex bonus compiled!/****$(RESET)"

all: libft ${NAME}

clean: libft
	@(cd ./libft && make clean > /dev/null 2>&1)
	@rm -f ${OBJS} ${OBJS_BONUS}
	@echo "$(RED)--->objects deleted<----$(RESET)"

fclean: clean
	@(cd ./libft && make fclean > /dev/null 2>&1)
	@rm -f ${NAME}
	@rm -f ${NAME_B}
	@echo "$(RED)---->pipex deleted<----$(RESET)"

re: fclean all

bonus: libft ${NAME_B}

.PHONY: all clean fclean re bonus