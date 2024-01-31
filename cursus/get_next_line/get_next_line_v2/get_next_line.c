/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:53:11 by migumore          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_text(int fd, char *read_text)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)ft_calloc((BUFFER_SIZE), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 || !ft_strchr(read_text, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		read_text = ft_strjoin(read_text, buffer);
	}
	free(buffer);
	return (read_text);
}

char	*ft_substr(char *read_text)
{
	char	*sub_s;
	size_t	i;

	i = 0;
	if (!read_text[i])
		return (NULL);
	while (read_text[i] && read_text[i] != '\n')
		i++;
	sub_s = (char *)ft_calloc((i + 2), sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (read_text[i] && read_text[i] != '\n')
	{
		sub_s[i] = read_text[i];
		i++;
	}
	if (read_text[i] == '\n')
	{
		sub_s[i] = read_text[i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

char	*ft_remaining_text(char *read_text)
{
	char	*sub_s;
	size_t	i;
	size_t	j;

	i = 0;
	while (read_text[i] && read_text[i] != '\n')
		i++;
	if (!read_text[i])
	{
		free(read_text);
		return (NULL);
	}
	sub_s = (char *)ft_calloc(ft_strlen(read_text) - i + 1, sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	i++;
	j = 0;
	while (read_text[i])
		sub_s[j++] = read_text[i++];
	sub_s[j] = '\0';
	free(read_text);
	return (sub_s);
}

char	*get_next_line(int fd)
{
	char	*read_text;
	char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_text = NULL;
	read_text = ft_get_text(fd, read_text);
	if (!read_text)
		return (NULL);
	line = ft_substr(read_text);
	read_text = ft_remaining_text(read_text);
	return (line);
}
