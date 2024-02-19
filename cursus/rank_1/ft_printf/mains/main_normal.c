/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:22:08 by migumore          #+#    #+#             */
/*   Updated: 2024/02/19 11:03:52 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	i;

	i = ft_printf(NULL);
	printf("\n%d\n", i);
	i = printf(NULL);
	printf("\n%d\n", i);
	return (0);
}
