/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:33:48 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:38 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = '0';
	if (isascii(c))
		printf("OG Your input is ASCII.\n");
	else
		printf("OG Your input is not ASCII.\n");
	if (ft_isascii(c))
		printf("MY Your input is ASCII.\n");
	else
		printf("MY Your input is not ASCII.\n");
	return (0);
}
