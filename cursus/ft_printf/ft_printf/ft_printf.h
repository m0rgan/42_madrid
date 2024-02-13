/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:34:37 by migumore          #+#    #+#             */
/*   Updated: 2024/02/13 16:10:14 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putnbr_base(unsigned long nbr, char *base);
void	ft_check_format(char format, va_list args);
int		ft_format(const char *format, va_list args);
int		ft_printf(const char *format, ...);

#endif