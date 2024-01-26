/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:10:26 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 13:23:35 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[end - 1]))
		end--;
	new_s = malloc(sizeof(char) * (end - start + 1));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		new_s[i] = s1[start];
		i++;
		start++;
	}
	new_s[i] = '\0';
	return (new_s);
}
