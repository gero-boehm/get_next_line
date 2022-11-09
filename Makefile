CC=gcc
CFLAGS=-Wall -Wextra -Werror -D BUFFER_SIZE=1 -g
NAME=libft.a
MANDATORY=get_next_line.o get_next_line_utils.o
BONUS=

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(MANDATORY)
	ar -crs $(NAME) $^

bonus: $(BONUS)
	ar -crs $(NAME) $^

test: $(MANDATORY) $(BONUS) main.o
	$(CC) -g -o $@ $^ && ./test

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all bonus clean fclean re
