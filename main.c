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

	// printf("%zu\n", strlen(""));

	close(fd);
}