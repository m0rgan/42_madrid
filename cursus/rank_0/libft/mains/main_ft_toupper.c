/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:54:16 by migumore          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:57 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'a';
	printf("OG Output: %c\n", toupper(c));
	printf("MY Output: %c\n", ft_toupper(c));
	return (0);
}
