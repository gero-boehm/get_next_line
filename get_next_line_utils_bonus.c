/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:02:58 by gbohm             #+#    #+#             */
/*   Updated: 2023/01/13 10:21:36 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_calloc2(size_t count, size_t size, char **ptr)
{
	size_t	total;
	char	*mem;

	total = count * size;
	mem = NULL;
	if (count && total / count != size)
		return (1);
	mem = malloc(total);
	if (mem == NULL)
		return (2);
	while (total--)
		mem[total] = 0;
	*ptr = mem;
	return (0);
}

int	ft_strappend(char **dst, char *src, int src_length)
{
	char	*new;
	int		dst_length;

	if (dst == NULL || src == NULL)
		return (1);
	if (src_length == 0)
		return (0);
	dst_length = 0;
	while ((*dst)[dst_length])
		dst_length++;
	if (ft_calloc2(dst_length + src_length + 1, sizeof(char), &new))
		return (2);
	while (src_length--)
		new[dst_length + src_length] = src[src_length];
	while (dst_length--)
		new[dst_length] = (*dst)[dst_length];
	free(*dst);
	free(src);
	*dst = new;
	return (0);
}

int	has_newline(char *str)
{
	while (*str && *str != '\n')
		str++;
	return (*str == '\n');
}

char	*free_all(int c, ...)
{
	va_list	args;
	void	**buffer;

	va_start(args, c);
	while (c--)
	{
		buffer = va_arg(args, void **);
		if (buffer == NULL)
			continue ;
		free(*buffer);
		*buffer = NULL;
	}
	va_end(args);
	return (NULL);
}

char	*cut(char **str)
{
	int		i;
	int		length;
	char	*cut;
	char	*leftover;

	if (!**str)
		return (free_all(1, str));
	length = 0;
	while ((*str)[length] && (!length || (length
		&& (*str)[length - 1] != '\n')))
		length++;
	i = length;
	while ((*str)[i])
		i++;
	if (ft_calloc2(i - length + 1, sizeof(char), &leftover))
		return (free_all(1, str));
	while (i-- > length)
		leftover[i - length] = (*str)[i];
	if (ft_calloc2(length + 1, sizeof(char), &cut))
		return (free_all(2, str, &leftover));
	while (length--)
		cut[length] = (*str)[length];
	free(*str);
	*str = leftover;
	return (cut);
}
