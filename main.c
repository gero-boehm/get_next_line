#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("\n\n%s\n", line);
	// close(fd);

	// fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("\n\n%s\n", line);
	close(fd);
}