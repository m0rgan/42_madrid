/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:17:13 by migumore          #+#    #+#             */
/*   Updated: 2024/02/01 11:25:14 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = (char *)ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		new_s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		new_s[len_s1 + i] = s2[i];
		i++;
	}
	new_s[len_s1 + i] = '\0';
	return (new_s);
}
