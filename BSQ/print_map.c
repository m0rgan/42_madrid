/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:38:36 by migumore          #+#    #+#             */
/*   Updated: 2023/11/27 19:41:35 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

void	putnbr(int nb)
{
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb = -nb;
		write (1, "-", 1);
		putnbr(nb);
	}
	else if (nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
		write (1, &(char){nb + 48}, 1);
}

void	print_map(t_mi *map_info)
{
	int		count;

	count = 0;
	putnbr(map_info[0].num_lines);
	write (1, &map_info[0].empty, 1);
	write (1, &map_info[0].obst, 1);
	write (1, &map_info[0].full, 1);
	write (1, "\n", 1);
	while (count < map_info[0].num_lines)
	{
		write(1, map_info[0].map[count], map_info[0].num_cols);
		count ++;
	}
}
