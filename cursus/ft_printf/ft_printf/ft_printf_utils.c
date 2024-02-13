/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:56 by migumore          #+#    #+#             */
/*   Updated: 2024/02/13 16:02:37 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

void	ft_putnbr(int n)
{
	char	d;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			d = '-';
			write(1, &d, 1);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10);
		d = '0' + n % 10;
		write(1, &d, 1);
	}
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (nbr >= len_base)
	{
		ft_putnbr_base(nbr / len_base, base);
		ft_putnbr_base(nbr % len_base, base);
	}
	else
		ft_putchar(base[nbr]);
}
