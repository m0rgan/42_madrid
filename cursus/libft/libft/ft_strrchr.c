/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:31:06 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 12:36:46 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*loc;

	loc = NULL;
	while (*s)
	{
		if (*s == (char)c)
			loc = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)loc);
}
