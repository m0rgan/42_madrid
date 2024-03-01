/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:36:17 by migumore          #+#    #+#             */
/*   Updated: 2024/02/23 17:40:08 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	binary_number;

	binary_number = 0b1010;
	ft_printf("ft_printf=The decimal value of  0b1010 is: %d\n", binary_number);
	printf("printf=The decimal value of 0b1010 is: %d\n", binary_number);
	return (0);
}
