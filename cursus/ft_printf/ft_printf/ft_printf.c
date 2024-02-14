/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:56 by migumore          #+#    #+#             */
/*   Updated: 2024/02/14 16:26:09 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
	{
		i += ft_putstr("0x");
		i += ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		i += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		i += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		i += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_format(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%' && *(format + i + 1) != '\0')
		{
			i++;
			count += ft_check_format(*(format + i), args);
		}
		else if (*(format + i) != '%')
			count += ft_putchar(*(format + i));
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
