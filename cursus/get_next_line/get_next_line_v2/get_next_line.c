/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:53:11 by migumore          #+#    #+#             */
/*   Updated: 2024/02/02 16:56:42 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_get_text(int fd, char *read_text)
{
	char	*buffer;
	char	*temp;
	int		bytes;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		temp = ft_strjoin(read_text, buffer);
		free(read_text);
		read_text = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
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
	line = (char *)ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, read_text, (i + 2));
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
	remaining = (char *)ft_calloc((ft_strlen(read_text) - i + 1), sizeof(char));
	if (!remaining)
		return (NULL);
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
	static char	*read_text;
	char		*line;

	if (read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_text)
	{
		read_text = (char *)ft_calloc(1, sizeof(char));
		if (!read_text)
			return (NULL);
		read_text[0] = '\0';
	}
	read_text = ft_get_text(fd, read_text);
	if (!read_text)
		return (NULL);
	line = ft_get_line(read_text);
	read_text = ft_remaining_text(read_text);
	return (line);
}
