CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = main.c read_file.c print_map.c measure_size.c find_square.c
NAME = bsq

$(NAME): $(SOURCE:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean all

clean:
	@rm -f $(NAME) $(SOURCE:.c=.o)

all: $(NAME)

.DEFAULT_GOAL := all