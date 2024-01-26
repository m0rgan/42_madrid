/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:54:16 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:54 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'a';
	printf("OG Output: %c\n", tolower(c));
	printf("MY Output: %c\n", ft_tolower(c));
	return (0);
}
