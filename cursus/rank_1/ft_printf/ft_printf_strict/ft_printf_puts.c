/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:56 by migumore          #+#    #+#             */
/*   Updated: 2024/02/15 19:47:13 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*(s + i))
	{
		if (ft_putchar(*(s + i)) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			if (ft_putchar('-') == -1)
				return (-1);
			n = -n;
			i++;
		}
		if (n > 9)
			i += ft_putnbr(n / 10);
		if (ft_putchar(n % 10 + '0') == -1)
			return (-1);
		i++;
		return (i);
	}
}

int	ft_putunbr(unsigned int n)
{
	int		i;

	i = 0;
	if (n > 9)
		i += ft_putunbr(n / 10);
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	i++;
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
	{
		if (ft_putchar(base[nbr]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
