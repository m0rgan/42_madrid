/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:56 by migumore          #+#    #+#             */
/*   Updated: 2024/02/15 22:13:33 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_case(unsigned long p)
{
	int	str;
	int	hex;

	str = ft_putstr("0x");
	hex = ft_putnbr_base(p, "0123456789abcdef");
	if (str == -1)
		return (-1);
	if (hex == -1)
		return (-1);
	return (str + hex);
}

int	ft_check_format(char format, va_list args)
{
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
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_format(const char *format, va_list args)
{
	int	i;
	int	result;
	int	count;

	i = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%' && *(format + i + 1) != '\0')
		{
			i++;
			result = ft_check_format(*(format + i), args);
			if (result == -1)
				return (-1);
			count += result;
		}
		else if (*(format + i) != '%')
		{
			result = ft_putchar(*(format + i));
			if (result == -1)
				return (-1);
			count += result;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_format(format, args);
	va_end(args);
	return (count);
}
