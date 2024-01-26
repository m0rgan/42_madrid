/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:38:36 by migumore          #+#    #+#             */
/*   Updated: 2023/11/30 11:57:06 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

void	print_map(t_mi *map_info)
{
	int		count;

	count = 0;
	while (count < map_info[0].num_lines)
	{
		write(1, map_info[0].map[count], map_info[0].num_cols);
		count ++;
	}
}
