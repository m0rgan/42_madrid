/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:22:08 by migumore          #+#    #+#             */
/*   Updated: 2024/02/16 11:04:09 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int    main(void)
{
	int i = 0;
    i = ft_printf("%p", (void *)-14523);
	printf("\n%d\n", i);
	i = printf("%p", (void *)-14523);
	printf("\n%d\n", i);
    return (0);
}
