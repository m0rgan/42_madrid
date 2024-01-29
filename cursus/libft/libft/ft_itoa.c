/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:18:07 by migumore          #+#    #+#             */
/*   Updated: 2024/01/29 12:14:14 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_transformation(char ***d, int n, int i)
{
	if (n < 0)
	{
		(**d)[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		(**d)[i] = '0' + n % 10;
		n /= 10;
		i--;
	}
}

static int	ft_memalloc(char **d, int n)
{
	int		i;
	int		temp;

	i = 0;
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	if (n < 0)
		i++;
	*d = malloc(sizeof(char) * (i + 1));
	if (*d == NULL)
		return (1);
	(*d)[i] = '\0';
	i--;
	ft_transformation(&d, n, i);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*d;
	int		check;

	if (n == -2147483648)
	{
		d = malloc(sizeof(char) * 12);
		if (d == NULL)
			return (NULL);
		ft_strlcpy(d, "-2147483648", 12);
	}
	else if (n == 0)
	{
		d = malloc(sizeof(char) * 2);
		if (d == NULL)
			return (NULL);
		d[0] = '0';
		d[1] = '\0';
	}
	else
	{
		check = ft_memalloc(&d, n);
		if (check == 1)
			return (NULL);
	}
	return (d);
}
