/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:53:11 by migumore          #+#    #+#             */
/*   Updated: 2024/02/08 17:43:26 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_read(int fd, char *buffer, char **read_text)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1 || bytes == 0)
			break ;
		buffer[bytes] = '\0';
		temp = ft_strjoin(*read_text, buffer);
		free(*read_text);
		*read_text = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
}

char	*ft_get_text(int fd, char *read_text)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(read_text);
		return (NULL);
	}
	ft_read(fd, buffer, &read_text);
	free(buffer);
	if (read_text && read_text[0] == '\0')
	{
		free(read_text);
		return (NULL);
	}
	return (read_text);
}

char	*ft_get_line(char *read_text)
{
	char	*line;
	int		i;

	if (!read_text)
		return (NULL);
	i = 0;
	while (read_text[i] && read_text[i] != '\n')
		i++;
	if (read_text[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
	{
		free(read_text);
		return (NULL);
	}
	ft_strlcpy(line, read_text, (i + 1));
	return (line);
}

char	*ft_remaining_text(char *read_text)
{
	char	*remaining;
	int		i;
	int		j;

	i = 0;
	while (read_text[i] && read_text[i] != '\n')
		i++;
	if (!read_text[i])
	{
		free(read_text);
		return (NULL);
	}
	remaining = (char *)malloc((ft_strlen(read_text) - i) * sizeof(char));
	if (!remaining)
	{
		free(read_text);
		return (NULL);
	}
	i++;
	j = 0;
	while (read_text[i])
		remaining[j++] = read_text[i++];
	remaining[j] = '\0';
	free(read_text);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*read_text[MAX_FDS];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FDS)
		return (NULL);
	if (read(fd, 0, 0))
	{
		free(read_text[fd]);
		read_text[fd] = NULL;
		return (NULL);
	}
	read_text[fd] = initialize_read_text(fd, read_text);
	if (!read_text[fd])
		return (NULL);
	read_text[fd] = ft_get_text(fd, read_text[fd]);
	if (!read_text[fd])
		return (NULL);
	line = ft_get_line(read_text[fd]);
	if (!line)
	{
		read_text[fd] = NULL;
		return (NULL);
	}
	read_text[fd] = ft_remaining_text(read_text[fd]);
	return (line);
}
