/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:25:38 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/10 10:31:58 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*last[1024] = {NULL};
	char		*buffer;
	int			bytes_read;

	if ((fd < 0 || fd > 1023) || (last[fd] == NULL
			&& !ft_calloc2(1, sizeof(char), &last[fd])))
		return (NULL);
	while (1)
	{
		if (has_newline(last[fd]))
			return (cut(&last[fd]));
		if (!ft_calloc2(BUFFER_SIZE + 1, sizeof(char), &buffer))
			return (free_all(1, &last[fd]));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (bytes_read == -1)
				return (free_all(1, &last[fd]));
			return (cut(&last[fd]));
		}
		if (!ft_strappend(&last[fd], buffer, bytes_read))
			return (free_all(2, &buffer, &last[fd]));
	}
	return (NULL);
}
