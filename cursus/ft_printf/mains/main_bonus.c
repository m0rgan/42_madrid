/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:24 by migumore          #+#    #+#             */
/*   Updated: 2024/02/14 14:47:26 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	double	pi;

	pi = 3.14159;
    // Left justify with zero padding and precision
	printf("Left justified with zero padding: %-010.2f\n", pi);
    // Right justified (default) with precision
	printf("Right justified with precision: %0.2f\n", pi);
	return (0);
}
