/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:54:01 by migumore          #+#    #+#             */
/*   Updated: 2024/02/01 18:11:12 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr != NULL)
		ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *read_text, char *buff)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (!read_text)
	{
		read_text = (char *)ft_calloc(1, sizeof(char));
		if (!read_text)
			return (NULL);
		read_text[0] = '\0';
	}
	if (!read_text || !buff)
		return (NULL);
	new_s = (char *)ft_calloc((ft_strlen(read_text) + ft_strlen(buff) + 1), 1);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (read_text[i])
		new_s[i++] = read_text[j++];
	j = 0;
	while (buff[j])
		new_s[i++] = buff[j++];
	new_s[i] = '\0';
	free(read_text);
	return (new_s);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	else
		return (NULL);
}
