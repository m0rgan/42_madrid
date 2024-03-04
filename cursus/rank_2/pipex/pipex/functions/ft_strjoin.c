/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:17:13 by migumore          #+#    #+#             */
/*   Updated: 2024/02/29 16:17:49 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

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
