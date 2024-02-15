/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:56 by migumore          #+#    #+#             */
/*   Updated: 2024/02/15 16:05:40 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*(s + i))
		i += ft_putchar(*(s + i));
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	else
	{
		if (n < 0)
		{
			i += ft_putchar('-');
			n = -n;
		}
		if (n > 9)
			i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + '0');
		return (i);
	}
}

int	ft_putunbr(unsigned int n)
{
	int		i;

	i = 0;
	if (n > 9)
		i += ft_putunbr(n / 10);
	i += ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	len_base;
	int				i;

	len_base = 0;
	i = 0;
	while (base[len_base])
		len_base++;
	if (nbr >= len_base)
	{
		i += ft_putnbr_base(nbr / len_base, base);
		i += ft_putnbr_base(nbr % len_base, base);
	}
	else
		i += ft_putchar(base[nbr]);
	return (i);
}
