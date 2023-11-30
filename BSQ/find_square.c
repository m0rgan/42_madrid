/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:50 by migumore          #+#    #+#             */
/*   Updated: 2023/11/30 11:56:29 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

void	replace_map(t_mi *map_info)
{
	int		count;
	int		count2;

	count = 0;
	while (count < map_info[0].sol_value)
	{
		count2 = 0;
		while (count2 < map_info[0].sol_value)
		{
			map_info[0].map[map_info[0].sol_y - count]
			[map_info[0].sol_x - count2] = map_info[0].full;
			count2 ++;
		}
		count ++;
	}
	count = 0;
	count2 = 0;
}

void	conds1(int count, int count2, t_mi *map_info)
{
	if (map_info[0].sol_map[count][count2 -1] <=
		map_info[0].sol_map[count -1][count2 -1] &&
		map_info[0].sol_map[count][count2 -1] <=
		map_info[0].sol_map[count -1][count2])
	{
		map_info[0].sol_map[count][count2]
			= map_info[0].sol_map[count][count2 -1] +1;
	}
	else if (map_info[0].sol_map[count -1][count2 -1]
	<= map_info[0].sol_map[count -1][count2] &&
		map_info[0].sol_map[count -1][count2 -1] <=
		map_info[0].sol_map[count][count2 -1])
	{
		map_info[0].sol_map[count][count2]
			= map_info[0].sol_map[count -1][count2 -1] +1;
	}
	else if (map_info[0].sol_map[count -1][count2]
	<= map_info[0].sol_map[count -1][count2 -1] &&
		map_info[0].sol_map[count -1][count2] <=
		map_info[0].sol_map[count][count2 -1])
	{
		map_info[0].sol_map[count][count2]
			= map_info[0].sol_map[count -1][count2] +1;
	}
}

void	conds2(int count, int count2, t_mi *map_info)
{
	if (map_info[0].sol_map[count][count2] > map_info[0].sol_value)
	{
		map_info[0].sol_value = map_info[0].sol_map[count][count2];
		map_info[0].sol_x = count2;
		map_info[0].sol_y = count;
	}
}

void	search(int *count, int *count2, t_mi *map_info)
{
	while (*count < map_info[0].num_lines)
	{
		*count2 = 0;
		while (*count2 < map_info[0].num_cols -1)
		{
			if (map_info[0].map[*count][*count2] == map_info[0].obst)
				map_info[0].sol_map[*count][*count2] = 0;
			else if (map_info[0].map[*count][*count2] == map_info[0].empty
				&& (*count == 0 || *count2 == 0))
				map_info[0].sol_map[*count][*count2] = 1;
			else
				conds1(*count, *count2, map_info);
			conds2(*count, *count2, map_info);
			*count2 = *count2 +1;
		}
		*count = *count +1;
	}
}

void	logic(t_mi *map_info)
{
	int	count;
	int	count2;

	count = 0;
	map_info[0].sol_map = (int **)malloc(sizeof(int *) * map_info[0].num_lines);
	while (count < map_info[0].num_lines)
	{
		map_info[0].sol_map[count]
			= (int *)malloc(sizeof(int) * map_info[0].num_cols);
		count ++;
	}
	count = 0;
	map_info[0].sol_x = 0;
	map_info[0].sol_y = 0;
	map_info[0].sol_value = 0;
	search(&count, &count2, map_info);
}
