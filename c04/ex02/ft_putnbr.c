/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:14:07 by migumore          #+#    #+#             */
/*   Updated: 2023/11/21 16:17:42 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbr(int nb)
{
	char	d;

	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			d = '-';
			write(1, &d, 1);
			nb = -nb;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		d = '0' + nb % 10;
		write(1, &d, 1);
	}
}
