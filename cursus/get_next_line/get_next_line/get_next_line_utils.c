/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:54:01 by migumore          #+#    #+#             */
/*   Updated: 2024/02/08 17:53:54 by migumore         ###   ########.fr       */
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
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		new_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * 1);
		if (new_s == NULL)
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
			new_s[j++] = s1[i++];
		j = 0;
		while (s2[j])
			new_s[i++] = s2[j++];
		new_s[i] = '\0';
		return (new_s);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
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

char	*initialize_read_text(char *read_text)
{
	if (!read_text)
	{
		read_text = (char *)malloc(sizeof(char));
		if (!read_text)
			return (NULL);
		read_text[0] = '\0';
	}
	return (read_text);
}
