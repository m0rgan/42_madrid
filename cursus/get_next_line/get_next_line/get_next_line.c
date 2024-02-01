/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:53:11 by migumore          #+#    #+#             */
/*   Updated: 2024/02/01 18:13:01 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_text(int fd, char *read_text, int *bytes)
{
	char	*buffer;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	*bytes = 1;
	while (*bytes != 0 && !ft_strchr(read_text, '\n'))
	{
		*bytes = read(fd, buffer, BUFFER_SIZE);
		if (*bytes == -1)
		{
			free(buffer);
			free(read_text);
			return (NULL);
		}
		buffer[*bytes] = '\0';
		read_text = ft_strjoin(read_text, buffer);
	}
	free(buffer);
	return (read_text);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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

char	*ft_substr_free_s(char *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub_s = ft_calloc((len + 1), sizeof(char));
	if (sub_s == NULL)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start];
		i++;
		start++;
	}
	sub_s[i] = '\0';
	free(s);
	return (sub_s);
}

char	*get_next_line(int fd)
{
	static char	*read_text;
	char		*line;
	size_t		len;
	int			bytes;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_text = ft_get_text(fd, read_text, &bytes);
	if (!read_text || bytes <= 0)
		return (NULL);
	len = 0;
	while (read_text[len] && !ft_strchr("\n", read_text[len]))
		len++;
	line = ft_substr(read_text, 0, (len + 1));
	read_text = ft_substr_free_s(read_text, (len + 1), ft_strlen(read_text));
	return (line);
}
