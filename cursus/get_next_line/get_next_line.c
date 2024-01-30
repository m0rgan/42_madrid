/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:53:11 by migumore          #+#    #+#             */
/*   Updated: 2024/01/30 19:08:23 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*read_text;
	char	*temp;
	size_t	bytes;
	size_t	i;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (NULL);
	i = 1;
	read_text = (char *)ft_calloc((BUFFER_SIZE), sizeof(char));
	temp = (char *)ft_calloc((BUFFER_SIZE), sizeof(char));
	if (!read_text || !temp)
		return (NULL);
	while (bytes > 0)
	{
		read_text = ft_strjoin(buffer, read_text);
		temp = ft_strjoin(read_text, temp);
		free(read_text);
		bytes = read(fd, buffer, BUFFER_SIZE);
		i++;
		read_text = (char *)ft_calloc((BUFFER_SIZE * i), sizeof(char));
		if (!read_text)
			return (NULL);
		read_text = ft_strjoin(temp, read_text);
		free(temp);
		temp = (char *)ft_calloc((BUFFER_SIZE * i), sizeof(char));
		if (!temp)
			return (NULL);
	}
	return (NULL);
}
