/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:22:08 by migumore          #+#    #+#             */
/*   Updated: 2024/02/15 15:54:57 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int    main(void)
{
	char *s = NULL;
	int i = 0;
    i = ft_printf("Hello, %s\n%c", s, 'M');
	printf("\n%d\n", i);
	i = printf("Hello, %s\n%c", s, 'M');
	printf("\n%d\n", i);
    return (0);
}
