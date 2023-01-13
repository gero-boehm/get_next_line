CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libget_next_line.a
MANDATORY_SRC=get_next_line.c get_next_line_utils.c
BONUS_SRC=get_next_line_bonus.c get_next_line_utils_bonus.c
MANDATORY_OBJ=$(MANDATORY_SRC:.c=.o)
BONUS_OBJ=$(BONUS_SRC:.c=.o)
HEADERS=get_next_line.h get_next_line_bonus.h

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(MANDATORY_OBJ)
	ar -crs $(NAME) $^

bonus: $(BONUS_OBJ)
	ar -crs $(NAME) $^

test: $(MANDATORY_OBJ) main.o
	$(CC) -g -o $@ $^ && ./test

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all bonus clean fclean re
