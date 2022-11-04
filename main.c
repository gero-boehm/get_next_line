#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "get_next_line.h"

void print(int fd)
{
	char *line = get_next_line(fd);
	printf("%s", line);

	if (strlen(line))
		print(fd);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);

	print(fd);

	close(fd);

	// char *t[2];

	// t[0] = "abcdef";
	// t[1] = "123456789";
	// t[2] = "123456789";
	// printf("%s\n", t[0]);
	// printf("%s\n", t[1]);
}