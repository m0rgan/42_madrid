/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:53:11 by migumore          #+#    #+#             */
/*   Updated: 2024/01/31 16:20:41 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_text(int fd, char *read_text, char *buffer)
{
	int		bytes;

	bytes = 1;
	read_text[0] = '\0';
	while (bytes > 0 || !ft_strchr(read_text, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(read_text);
			return (NULL);
		}
		buffer[bytes] = '\0';
		read_text = ft_strjoin(read_text, buffer);
	}
	free(buffer);
	return (read_text);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub_s = ft_calloc((len + 1), sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start];
		i++;
		start++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*read_text;
	int		line_len;
	char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)ft_calloc((BUFFER_SIZE), sizeof(char));
	if (!buffer)
		return (NULL);
	read_text = (char *)ft_calloc(1, sizeof(char));
	if (!read_text)
	{
		free(buffer);
		return (NULL);
	}
	read_text = ft_get_text(fd, read_text, buffer);
	if (!read_text)
		return (NULL);
	line_len = 0;
	while (read_text[line_len] && !ft_strchr("\n", read_text[line_len]))
		line_len++;
	line = ft_substr(read_text, 0, (line_len + 1));
	read_text = ft_substr(read_text, (line_len + 1), ft_strlen(read_text));
	return (line);
}
