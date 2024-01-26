/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:19:07 by migumore          #+#    #+#             */
/*   Updated: 2023/11/17 13:14:09 by migumore         ###   ########.fr       */
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
