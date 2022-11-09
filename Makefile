CC=cc
CFLAGS=-Wall -Wextra -Werror -D BUFFER_SIZE=20
NAME=get_next_line.a
MANDATORY_SRC=get_next_line.c get_next_line_utils.c
BONUS_SRC=
MANDATORY_OBJ=$(MANDATORY_SRC:.c=.o)
BONUS_OBJ=$(BONUS_SRC:.c=.o)
INCLUDES=libft.h

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(MANDATORY_OBJ)
	ar -crs $(NAME) $^

bonus: $(MANDATORY_OBJ) $(BONUS_OBJ)
	ar -crs $(NAME) $^

test: $(MANDATORY_OBJ) $(BONUS_OBJ) main.o
	$(CC) -g -o $@ $^ && ./test

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all bonus clean fclean re
