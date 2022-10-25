/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:25:38 by gbohm             #+#    #+#             */
/*   Updated: 2022/10/25 13:24:56 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	get_line_length(char *str)
{
	size_t	length;

	length = 0;
	while (str[length] && str[length - 1] != '\n')
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
	while (length < size)
	{
		str[i] = buffer[length];
		i++;
		length++;
	}
	return (str);
}

char	*free_all(char *buffer, char *str)
{
	free(buffer);
	free(str);
	return (NULL);
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
		new = increase_buffer(str, length);
		if (new == NULL)
			return (free_all(buffer, str));
		str = ft_strappend(new, buffer);
		if (length < BUFFER_SIZE)
		{
			last = get_last(buffer, BUFFER_SIZE, length);
			if (last == NULL)
				return (free_all(buffer, str));
			return (str);
		}
	}
	return (NULL);
}
