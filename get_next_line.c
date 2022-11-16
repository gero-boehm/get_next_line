/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:25:38 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/14 09:30:42 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*last = NULL;
	char		*buffer;
	int			bytes_read;

	if ((fd < 0 || fd > 1023) || (BUFFER_SIZE <= 0)
		|| (last == NULL && !ft_calloc2(1, sizeof(char), &last)))
		return (NULL);
	while (1)
	{
		if (has_newline(last))
			return (cut(&last));
		if (!ft_calloc2(BUFFER_SIZE + 1, sizeof(char), &buffer))
			return (free_all(1, &last));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (bytes_read == -1)
				return (free_all(1, &last));
			return (cut(&last));
		}
		if (!ft_strappend(&last, buffer, bytes_read))
			return (free_all(2, &buffer, &last));
	}
	return (NULL);
}
