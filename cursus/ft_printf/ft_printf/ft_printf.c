/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:56 by migumore          #+#    #+#             */
/*   Updated: 2024/02/13 16:13:22 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_format(char format, va_list args)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int));
	else if (format == 's')
		ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		ft_putnbr(va_arg(args, unsigned int));
	else if (format == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		ft_putchar('%');
}

int	ft_format(const char *format, va_list args)
{
	int		count;

	count = 0;
	while (format[count] != '\0')
	{
		if (format[count] == '%')
		{
			count++;
			ft_check_format(format[count], args);
		}
		else
			ft_putchar(format[count]);
		count++;
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
