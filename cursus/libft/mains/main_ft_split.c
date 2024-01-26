/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:14:37 by migumore          #+#    #+#             */
/*   Updated: 2024/01/23 12:32:05 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && i > 0 && s[i - 1] == c) || (s[i] != c && i == 0))
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
		free(array_s[i]);
		i--;
	}
	free(array_s);
}

static size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub_s = malloc(sizeof(char) * (len + 1));
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

char	**split_to_array(char **array_s, char const *s, char c, size_t words)
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
	array_s[words] = NULL;
	return (array_s);
}

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello!", ' ');
	i = 0;
	while (words[i] != NULL)
	{
		printf("%s\n", words[i]);
		i++;
	}
	return (0);
}
