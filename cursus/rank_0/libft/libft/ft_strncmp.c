/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:39:07 by migumore          #+#    #+#             */
/*   Updated: 2024/01/18 14:43:23 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if ((*s1 < *s2) || (*s1 > *s2))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		i++;
		s1++;
		s2++;
	}
	return (0);
}
