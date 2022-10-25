/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:02:58 by gbohm             #+#    #+#             */
/*   Updated: 2022/10/25 10:41:45 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strappend(char *a, char *b)
{
	size_t	length;
	char	*cursor;

	if (a == NULL || b == NULL)
		return (NULL);
	length = ft_strlen(a);
	cursor = a + length;
	while (*b && *b != '\n')
		*cursor++ = *b++;
	return (a);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	char	*mem;

	total = count * size;
	if (count && total / count != size)
		return (NULL);
	mem = malloc(total);
	if (mem == NULL)
		return (NULL);
	while (total-- > 0)
		mem[total] = 0;
	return ((void *) mem);
}

char	*increase_buffer(char *buffer, size_t increment)
{
	size_t	length;
	char	*new;

	if (buffer == NULL)
		return (ft_calloc(increment + 1, sizeof(char)));
	if (increment == 0)
		return (buffer);
	length = ft_strlen(buffer) + 1;
	new = ft_calloc(length + increment, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strappend(new, buffer);
	free(buffer);
	return (new);
}
