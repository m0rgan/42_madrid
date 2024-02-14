/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:21:36 by migumore          #+#    #+#             */
/*   Updated: 2024/02/14 14:26:14 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	i;

	i = ft_printf("\001\002\007\v\010\f\r\n");
	ft_printf("Return value: %d\n", i);
	i = printf("\001\002\007\v\010\f\r\n");
	printf("Return value: %d\n", i);
	return (0);
}
