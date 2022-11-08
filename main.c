#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "get_next_line.h"

int i = 0;

void print(int fd)
{
	char *line = get_next_line(fd);
	int next = line != NULL;
	printf("%s", line);
	free(line);
	// printf("%3d: %s", i++, line);

	if (next)
		print(fd);
}

int main(void)
{
	// char *str = strdup("");
	// char *lin = cut(&str);
	// printf("a: '%s' %d\n", lin, 0);
	// printf("b: '%s' %lu\n", str, strlen(str));

	int fd = open("test.txt", O_RDONLY);

	// char *buffer = calloc(1000, 1);
	// int c = read(fd, buffer, 1000);
	// printf("%d\n", c);
	// c = read(fd, buffer, 1000);
	// printf("%d\n", c);

	print(fd);

	// char *line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);

	close(fd);

	// char *str = strdup("this");
	// printf("%s\n", str);
	// ft_strappend(&str, " is", 3);
	// printf("%s\n", str);
	// ft_strappend(&str, " a", 2);
	// printf("%s\n", str);
	// ft_strappend(&str, " test", 5);
	// printf("%s\n", str);

	// char *str = strdup("this line has\n a new line.");
	// char *str = strdup("this is a single line\n");
	// char *str = strdup("this is eof");
	// char *lin = cut(&str);

	// printf("a: '%s' %lu\n", lin, strlen(lin));
	// printf("b: '%s' %lu\n", str, strlen(str));


	// char *str = strdup("a\nb\nc\nd\ne\nf\ng");
	// char *lin = cut(&str);
	// printf("a: '%s' %lu\n", lin, strlen(lin));
	// printf("b: '%s' %lu\n", str, strlen(str));
	// lin = cut(&str);
	// printf("a: '%s' %lu\n", lin, strlen(lin));
	// printf("b: '%s' %lu\n", str, strlen(str));
	// lin = cut(&str);
	// printf("a: '%s' %lu\n", lin, strlen(lin));
	// printf("b: '%s' %lu\n", str, strlen(str));
	// lin = cut(&str);
	// printf("a: '%s' %lu\n", lin, strlen(lin));
	// printf("b: '%s' %lu\n", str, strlen(str));
	// lin = cut(&str);
	// printf("a: '%s' %lu\n", lin, strlen(lin));
	// printf("b: '%s' %lu\n", str, strlen(str));
	// lin = cut(&str);
	// printf("a: '%s' %lu\n", lin, strlen(lin));
	// printf("b: '%s' %lu\n", str, strlen(str));


	// char *t[2];

	// t[0] = "abcdef";
	// t[1] = "123456789";
	// t[2] = "123456789";
	// printf("%s\n", t[0]);
	// printf("%s\n", t[1]);
}