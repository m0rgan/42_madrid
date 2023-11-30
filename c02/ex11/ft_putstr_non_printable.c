/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:44:55 by migumore          #+#    #+#             */
/*   Updated: 2023/11/23 21:06:16 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	bs;
	char	hex_val[2];
	char	*hex_chars;

	i = 0;
	bs = 92;
	hex_chars = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, &bs, 1);
			hex_val[0] = hex_chars[str[i] / 16];
			hex_val[1] = hex_chars[str[i] % 16];
			write(1, hex_val, 2);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
