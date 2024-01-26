/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:33:48 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:36 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = '0';
	if (isalpha(c))
		printf("OG Your input is alphabetical.\n");
	else
		printf("OG Your input is not alphabetical.\n");
	if (ft_isalpha(c))
		printf("MY Your input is alphabetical.\n");
	else
		printf("MY Your input is not alphabetical.\n");
	return (0);
}
