/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:53:11 by migumore          #+#    #+#             */
/*   Updated: 2024/01/29 11:27:01 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	c;
	size_t	bytes;
	char	*line;
	int	i;

	bytes = read(fd, &c, 1);
	while (c != '\n')
		bytes += read(fd, &c, 1);
	if (bytes == -1)
		return (NULL);
	line = (char *)malloc(sizeof(char) * bytes + 1);
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
