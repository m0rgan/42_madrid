/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:33:48 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:43 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = '0';
	if (isprint(c))
		printf("OG Your input is print.\n");
	else
		printf("OG Your input is not print.\n");
	if (ft_isprint(c))
		printf("MY Your input is print.\n");
	else
		printf("MY Your input is not print.\n");
	return (0);
}
