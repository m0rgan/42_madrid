/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:15:52 by migumore          #+#    #+#             */
/*   Updated: 2024/02/28 18:01:44 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i > 0 && s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_word_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_freemem(char **array_s, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array_s[i]);
	}
	free(array_s);
}

char	**split_to_array(char **array_s, char const *s, char c, size_t	words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] && s[j] == c)
			j++;
		array_s[i] = ft_substr(s, j, ft_word_size((s + j), c));
		if (array_s[i] == NULL)
		{
			ft_freemem(array_s, i);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	array_s[i] = NULL;
	return (array_s);
}

char	**ft_split(char const *s, char c)
{
	char	**array_s;
	size_t	words;

	words = ft_count_words(s, c);
	array_s = malloc(sizeof(char *) * (words + 1));
	if (array_s == NULL)
		return (NULL);
	array_s = split_to_array(array_s, s, c, words);
	return (array_s);
}
