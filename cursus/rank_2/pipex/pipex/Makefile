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
        utils/ft_get_cmd.c \
		utils/ft_split_command.c
SOURCE = $(MANDATORY) $(UTILS)
SOURCE_BONUS = $(BONUS) $(UTILS)
OBJS = $(SOURCE:.c=.o)
OBJS_BONUS = $(SOURCE_BONUS:.c=.o)
INCLS = -Iincludes
PROG = pipex
PROG_BONUS = pipex_bonus

.c.o: %.o: %.c
	@${CC} ${CFLAGS} ${INCLS} -c $< -o ${<:.c=.o}

all: $(PROG)

${PROG}: ${OBJS}
	@echo "$(BLUE)<----compiling libft---->$(RESET)"
	@make re -C ./libft &
	@for i in {1..2}; do \
		echo "$(BLUE).$(RESET)"; \
		sleep 1; \
	done
	@echo "$(GREEN)<----libft compiled!---->$(RESET)"
	@echo "$(YELLOW)****/compiling pipex\****$(RESET)"
	@$(CC) ${OBJS} -Llibft -lft -o ${PROG}
	@for i in {1..1}; do \
		echo "$(YELLOW).$(RESET)"; \
		sleep 1; \
	done
	@echo "$(GREEN)****\pipex compiled!/****$(RESET)"

bonus: $(PROG_BONUS)

${PROG_BONUS}: ${OBJS_BONUS}
	@echo "$(BLUE)<----compiling libft---->$(RESET)"
	@make re -C ./libft &
	@for i in {1..2}; do \
		echo "$(BLUE).$(RESET)"; \
		sleep 1; \
	done
	@echo "$(GREEN)<----libft compiled!---->$(RESET)"
	@echo "$(YELLOW)****/compiling pipex bonus\****$(RESET)"
	@$(CC) ${OBJS_BONUS} -Llibft -lft -o ${PROG_BONUS}
	@for i in {1..1}; do \
		echo "$(YELLOW).$(RESET)"; \
		sleep 1; \
	done
	@echo "$(GREEN)****\pipex bonus compiled!/****$(RESET)"

clean:
	@make clean -C ./libft
	@rm -f ${OBJS} ${OBJS_BONUS}
	@echo "$(RED)--->objects deleted<----$(RESET)"

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@rm -f ${PROG}
	@rm -f ${PROG_BONUS}
	@echo "$(RED)---->pipex deleted<----$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus