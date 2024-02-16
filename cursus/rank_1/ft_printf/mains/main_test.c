/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:13:55 by migumore          #+#    #+#             */
/*   Updated: 2024/02/15 22:23:15 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    char c = 'A';
    char *s = "Hello, World!";
    void *p = &c;
    int d = -123;
    int i = 123;
    unsigned int u = 123;
    unsigned int x = 0xabc;
    unsigned int X = 0xABC;

    printf("printf:\n");
    printf("c: %c\n", c);
    printf("s: %s\n", s);
    printf("p: %p\n", p);
    printf("d: %d\n", d);
    printf("i: %i\n", i);
    printf("u: %u\n", u);
    printf("x: %x\n", x);
    printf("X: %X\n", X);
    printf("%%\n");

    printf("\nft_printf:\n");
    ft_printf("c: %c\n", c);
    ft_printf("s: %s\n", s);
    ft_printf("p: %p\n", p);
    ft_printf("d: %d\n", d);
    ft_printf("i: %i\n", i);
    ft_printf("u: %u\n", u);
    ft_printf("x: %x\n", x);
    ft_printf("X: %X\n", X);
    ft_printf("%%\n");

	char c2 = CHAR_MAX;
    int d2 = INT_MIN;
    int i2 = INT_MAX;
    unsigned int u2 = UINT_MAX;
    long p2 = LONG_MAX;
    unsigned long x2 = ULONG_MAX;

    printf("printf:\n");
    printf("c: %c\n", c2);
    printf("d: %d\n", d2);
    printf("i: %i\n", i2);
    printf("u: %u\n", u2);
    printf("p: %ld\n", p2);
    printf("x: %lx\n", x2);
    printf("%%\n");

    printf("\nft_printf:\n");
    ft_printf("c: %c\n", c2);
    ft_printf("d: %d\n", d2);
    ft_printf("i: %i\n", i2);
    ft_printf("u: %u\n", u2);
    ft_printf("p: %ld\n", p2);
    ft_printf("x: %lx\n", x2);
    ft_printf("%%\n");

    return 0;
}
