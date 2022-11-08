/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:02:58 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/08 14:42:06 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include <stdio.h>


int	ft_calloc2(size_t count, size_t size, char **ptr)
{
	size_t	total;
	char	*mem;

	total = count * size;
	printf("ft_calloc2 total: %lu\n", total);
	if (count && total / count != size)
		return (0);
	printf("%ld before malloc\n", total);
	mem = malloc(total);
	printf("'%s'\n", mem);
	if (mem == NULL)
		return (0);
	printf("after malloc\n");
	while (total--)
		mem[total] = 0;
	*ptr = mem;
	return (1);
}

int	ft_strappend(char **dst, char *src, int src_length)
{
	char	*new;
	int		dst_length;

	if (dst == NULL || src == NULL)
		return (0);
	if (src_length == 0)
		return (1);
	dst_length = 0;
	while ((*dst)[dst_length])
		dst_length++;
	if (!ft_calloc2(dst_length + src_length + 1, sizeof(char), &new))
		return (0);
	while (src_length--)
		new[dst_length + src_length] = src[src_length];
	while (dst_length--)
		new[dst_length] = (*dst)[dst_length];
	free(*dst);
	free(src);
	*dst = new;
	return (1);
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
	return (NULL);
}

char	*cut(char **str)
{
	int		i;
	int		length;
	char	*cut;
	char	*leftover;

	if (!**str)
		return (NULL);
	length = 0;
	while ((*str)[length] && (!length || (length
		&& (*str)[length - 1] != '\n')))
		length++;
	i = length;
	while ((*str)[i])
		i++;
	if (!ft_calloc2(i - length + 1, sizeof(char), &leftover))
		return (NULL);
	printf("%d\n", i - length + 1);
	// free(leftover);
	printf("zaz\n");
	while (i-- >= length)
		leftover[i - length] = (*str)[i];
	printf("len %d\n", length + 1);
	if (!ft_calloc2(length + 1, sizeof(char), &cut))
	{
		printf("failed..\n");
		return (free_all(1, &leftover));
	}
	while (length--)
		cut[length] = (*str)[length];
	printf("1\n");
	free(*str);
	printf("2\n");
	*str = leftover;
	printf("3\n");
	// free(leftover);
	printf("4\n");
	return (cut);
}
