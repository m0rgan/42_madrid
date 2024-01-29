/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:53:11 by migumore          #+#    #+#             */
/*   Updated: 2024/01/29 18:06:06 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	size_t	bytes;
	int		line_len;
	char	*line;
	int		i;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (NULL);
	line_len = ;
	line = (char *)malloc(sizeof(char));
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
