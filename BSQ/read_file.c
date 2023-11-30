/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:56:43 by migumore          #+#    #+#             */
/*   Updated: 2023/11/29 18:41:04 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

void	extract_map(char *file, t_mi *map_info)
{
	char	*buffer;
	int		count;
	int		count2;

	buffer = malloc(sizeof(char) * map_info[0].num_cols);
	count = 0;
	map_info[0].file_desc = open(file, O_RDONLY);
	read(map_info[0].file_desc, buffer, map_info[0].line1_size +1);
	read(map_info[0].file_desc, buffer, map_info[0].num_cols);
	while (count < map_info[0].num_lines)
	{
		count2 = 0;
		while (count2 < map_info[0].num_cols)
		{
			map_info[0].map[count][count2] = buffer[count2];
			count2 ++;
		}
		count++;
		read(map_info[0].file_desc, buffer, map_info[0].num_cols);
	}
	close(map_info[0].file_desc);
}

int	file_valid(char *buffer, t_mi *map_info)
{
	if (map_info[0].file_desc == -1)
		return (1);
	if (read(map_info[0].file_desc, buffer, 1) == 0)
		return (1);
	if (get_map_info(buffer, map_info) == 1)
	{
		close(map_info[0].file_desc);
		return (1);
	}
	return (0);
}

void	free_memory(t_mi *map_info)
{
	int	count;

	count = 0;
	while (count < map_info[0].num_lines)
	{
		free(map_info[0].map[count]);
		free(map_info[0].sol_map[count]);
		count ++;
	}
	free(map_info[0].map);
	free(map_info[0].sol_map);
}

int	read_file(char *file)
{
	char	buffer[1];
	t_mi	map_info;
	int		count;

	count = 0;
	map_info.num_lines = 0;
	map_info.num_cols = 0;
	map_info.file_desc = open(file, O_RDONLY);
	map_info.empty = 0;
	if (file_valid(buffer, &map_info) == 1)
		return (1);
	map_info.map = (char **)malloc(sizeof(char *) * map_info.num_lines);
	if (map_info.map == 0)
		return (1);
	while (count < map_info.num_lines)
	{
		map_info.map[count] = (char *)malloc(sizeof(char) * map_info.num_cols);
		count ++;
	}
	extract_map(file, &map_info);
	logic(&map_info);
	replace_map(&map_info);
	print_map(&map_info);
	free_memory(&map_info);
	return (0);
}
