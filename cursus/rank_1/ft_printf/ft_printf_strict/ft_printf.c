/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:56 by migumore          #+#    #+#             */
/*   Updated: 2024/02/19 11:00:57 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_case(unsigned long p)
{
	int	str;
	int	hex;

	str = ft_putstr("0x");
	if (str == -1)
		return (-1);
	hex = ft_putnbr_base(p, "0123456789abcdef", 0);
	if (hex == -1)
		return (-1);
	return (str + hex);
}

int	ft_check_format(char format, va_list args)
{
	char	*hex_low;
	char	*hex_up;

	hex_low = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_pointer_case(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), hex_low, 0));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), hex_up, 0));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_format(const char *format, va_list args, int *i)
{
	int	result;
	int	count;

	count = 0;
	if (*(format + *i) == '%' && *(format + *i + 1) != '\0')
	{
		(*i)++;
		result = ft_check_format(*(format + *i), args);
		if (result == -1)
			return (-1);
		count += result;
	}
	else if (*(format + *i) != '%')
	{
		result = ft_putchar(*(format + *i));
		if (result == -1)
			return (-1);
		count += result;
	}
	(*i)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		result;

	va_start(args, format);
	i = 0;
	count = 0;
	if (!format)
		count = 0;
	else
	{
		while (*(format + i))
		{
			result = ft_format(format, args, &i);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
		}
	}
	va_end(args);
	return (count);
}
