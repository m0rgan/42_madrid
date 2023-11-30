rush-02 : main.o logic.o ft_atoi.o ft_strcpy.o ft_strlen.o
	gcc -Wall -Wextra -Werror main.o logic.o ft_atoi.o ft_strcpy.o ft_strlen.o  -o rush-02

main.o : main.c logic.c ft_atoi.c ft_strcpy.c ft_strlen.c

logic.o : logic.c main.c ft_atoi.c ft_strcpy.c ft_strlen.c

ft_atoi.o : ft_atoi.c main.c logic.c ft_strcpy.c ft_strlen.c

ft_strcpy.o : ft_strcpy.c main.c logic.c ft_atoi.c ft_strlen.c

ft_strlen.o : ft_strlen.c main.c logic.c ft_atoi.c ft_strcpy.c

.PHONYf : fclean
fclean :
	@rm -f *.o rush-02
