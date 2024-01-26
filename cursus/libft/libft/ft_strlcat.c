/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:54:51 by migumore          #+#    #+#             */
/*   Updated: 2024/01/18 13:54:49 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	if (dstsize == 0 || dstsize <= len_dst)
		return (dstsize + len_src);
	else
	{
		while (i < dstsize - 1 && src[i - len_dst])
		{
			dst[i] = src[i - len_dst];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_dst + len_src);
}
