/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:56 by migumore          #+#    #+#             */
/*   Updated: 2024/02/19 11:10:13 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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
	int	i;

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
		return (ft_putunbr(n) + i);
	}
}

int	ft_putunbr(unsigned int n)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (n > 9)
	{
		result = ft_putunbr(n / 10);
		if (result == -1)
			return (-1);
		i += result;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	i++;
	return (i);
}

int	ft_putnbr_base(unsigned long nbr, char *base, int result)
{
	unsigned long	len_base;

	len_base = 0;
	if (result == -1)
		return (-1);
	while (base[len_base])
		len_base++;
	if (nbr >= len_base)
	{
		result = ft_putnbr_base(nbr / len_base, base, result);
		if (result == -1)
			return (-1);
		result = ft_putnbr_base(nbr % len_base, base, result);
		if (result == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(base[nbr]) == -1)
			return (-1);
		result++;
	}
	return (result);
}
