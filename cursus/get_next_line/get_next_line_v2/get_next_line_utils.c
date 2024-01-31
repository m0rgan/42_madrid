/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:54:01 by migumore          #+#    #+#             */
/*   Updated: 2024/01/31 16:50:45 by migumore         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new_s = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (new_s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[i++] != '\0')
			new_s[i] = s1[i];
	while (s2[j] != '\0')
		new_s[i++] = s2[j++];
	new_s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new_s);
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
