/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:53:11 by migumore          #+#    #+#             */
/*   Updated: 2024/01/30 11:57:06 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*line;
	size_t	line_len;
	int		i;

	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	line_len = 0;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		while (buffer && ft_strchr(buffer, '\n'))
			line_len++;
	}
	line = (char *)ft_calloc(line_len, sizeof(char));
	i = 0;
	while (i < bytes)
	{
		read(fd, &c, 1);
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return (line);
}
