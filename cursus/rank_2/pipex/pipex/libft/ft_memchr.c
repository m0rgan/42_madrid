/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:58:17 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 13:37:15 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	*loc;
	size_t			i;

	cs = (unsigned char *)s;
	loc = NULL;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
		{
			loc = &cs[i];
			return (loc);
		}
		i++;
	}
	return (loc);
}
