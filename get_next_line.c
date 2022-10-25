/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:25:38 by gbohm             #+#    #+#             */
/*   Updated: 2022/10/25 12:56:31 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>


// char	*get_next_line(int fd)
// {
// 	char	*buf;
// 	int		i;

// 	buf = NULL;
// 	i = 0;
// 	while (1)
// 	{
// 		buf = increase_buffer(buf);
// 		read(fd, &c, 1);
// 	}
// 	printf("BUFFER_SIZE %d\n", BUFFER_SIZE);

// 	c = 32;
// 	while (c && c != '\n')
// 	{
// 		read(fd, &c, 1);
// 		printf("%c", c);
// 	}
// 		read(fd, &c, 1);

// 	while (c && c != '\n')
// 	{
// 		read(fd, &c, 1);
// 		printf("%c", c);
// 	}

// 	printf("\n");

// 	return malloc(1);
// }

size_t	get_line_length(char *str)
{
	size_t	length;

	length = 0;
	while (str[length] && str[length] != '\n')
		length++;
	return (length);
}

char	*get_last(char *buffer, int size, int length)
{
	int		i;
	int		count;
	char	*str;

	count = size - length;
	str = ft_calloc(count + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (size < length)
	{
		str[i] = buffer[size];
		i++;
		size++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*last;
	char		*str;
	char		*buffer;
	char		*new;
	size_t		length;

	str = last;
	while (1)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read(fd, buffer, BUFFER_SIZE);
		length = get_line_length(buffer);
		// printf("%s\n", buffer);
		// printf("%zu\n", length);
		new = increase_buffer(str, length);
		// return (NULL);
		if (new == NULL)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		str = ft_strappend(new, buffer);
		// printf("=== %s\n", str);
		if (length < BUFFER_SIZE)
		{
			last = get_last(buffer, BUFFER_SIZE, length);
			if (last == NULL)
			{
				free(buffer);
				free(str);
				return (NULL);
			}
			printf("%s\n". last)
			return (str);
		}
	}
	return (NULL);
}
