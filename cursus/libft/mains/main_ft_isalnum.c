/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:04 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:33 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = '0';
	if (isalnum(c))
		printf("OG Your input is alphanumeric.\n");
	else
		printf("OG Your input is not alphanumeric.\n");
	if (ft_isalnum(c))
		printf("OG Your input is alphanumeric.\n");
	else
		printf("OG Your input is not alphanumeric.\n");
	return (0);
}
