/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:11:08 by migumore          #+#    #+#             */
/*   Updated: 2024/02/14 17:02:33 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	signed char			sc = -123;
	unsigned char		uc = 123;
	short				si = -32768;
	unsigned short		usi = 65535;
	int					i = -2147483648;
	unsigned int		ui = 4294967295U;
	long				l = -9223372036854775807L;
	unsigned long		ul = 18446744073709551615UL;
	long long			sli = -9223372036854775807LL;
	unsigned long long	suli = 18446744073709551615ULL;
	float				f = 3.14159f;
	double				d = 3.141592653589793;
	long double			ld = 3.141592653589793238L;
	void				*p = NULL;
	wchar_t				wc = L'A';
	char				str[] = "Hello, World!";

	printf("signed char: %hhd\n", sc);
	printf("unsigned char: %hhu\n", uc);
	printf("short: %hd\n", si);
	printf("unsigned short: %hu\n", usi);
	printf("int: %d\n", i);
	printf("unsigned int: %u\n", ui);
	printf("long: %ld\n", l);
	printf("unsigned long: %lu\n", ul);
	printf("long long: %lld\n", sli);
	printf("unsigned long long: %llu\n", suli);
	printf("float: %f\n", f);
	printf("double: %f\n", d);
	printf("long double: %Lf\n", ld);
	printf("pointer: %p\n", p);
	printf("wide character: %lc\n", wc);
	printf("string: %s\n", str);
	write(1, "----------------------------------------", 41);
	ft_printf("signed char: %hhd\n", sc);
	ft_printf("unsigned char: %hhu\n", uc);
	ft_printf("short: %hd\n", si);
	ft_printf("unsigned short: %hu\n", usi);
	ft_printf("int: %d\n", i);
	ft_printf("unsigned int: %u\n", ui);
	ft_printf("long: %ld\n", l);
	ft_printf("unsigned long: %lu\n", ul);
	ft_printf("long long: %lld\n", sli);
	ft_printf("unsigned long long: %llu\n", suli);
	ft_printf("float: %f\n", f);
	ft_printf("double: %f\n", d);
	ft_printf("long double: %Lf\n", ld);
	ft_printf("pointer: %p\n", p);
	ft_printf("wide character: %lc\n", wc);
	ft_printf("string: %s\n", str);

	return (0);
}
