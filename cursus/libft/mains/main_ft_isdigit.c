/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:33:48 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:41 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = '0';
	if (isdigit(c))
		printf("OG Your input is digit.\n");
	else
		printf("OG Your input is not digit.\n");
	if (ft_isdigit(c))
		printf("MY Your input is digit.\n");
	else
		printf("MY Your input is not digit.\n");
	return (0);
}
