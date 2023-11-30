/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:10:32 by migumore          #+#    #+#             */
/*   Updated: 2023/11/29 17:59:20 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

int	first_line_data(char *buffer, int *count, t_mi *info)
{
	ssize_t	bytes;

	while (buffer[0] != '\n')
	{
		if (buffer[0] != '\n')
		{
			info[0].line1[*count] = buffer[0];
			*count = *count +1;
		}
		bytes = read(info[0].file_desc, buffer, 1);
		if (*count == 14 || bytes == 0)
			return (1);
	}
	info[0].full = info[0].line1[*count -1];
	info[0].obst = info[0].line1[*count -2];
	info[0].empty = info[0].line1[*count -3];
	info[0].line1_size = *count;
	return (0);
}

int	check_chars_first_line(t_mi *info)
{
	if (info[0].empty == info[0].full || info[0].empty == info[0].obst
		|| info[0].full == info[0].obst || info[0].empty < 32
		|| info[0].empty > 126 || info[0].full < 32
		|| info[0].full > 126 || info[0].obst < 32
		|| info[0].obst > 126)
		return (1);
	return (0);
}

int	atoi_measure(char *buffer, int *count, int *count2, t_mi *info)
{
	ssize_t	bytes;

	while (*count2 < *count -3)
	{
		if (info[0].line1[*count2] < '0' || info[0].line1[*count2] > '9')
			return (1);
		info[0].num_lines = (info[0].num_lines * 10)
			+ (info[0].line1[*count2] -48);
		*count2 = *count2 +1;
	}
	*count = 1;
	bytes = read(info[0].file_desc, buffer, 1);
	while (buffer[0] != '\n')
	{
		if ((buffer[0] != info[0].obst && buffer[0] != info[0].empty)
			|| bytes == 0)
			return (1);
		bytes = read(info[0].file_desc, buffer, 1);
		*count = *count +1;
	}
	return (0);
}

int	check_chars_map(char *buffer, int *count, int *count2, t_mi *info)
{
	ssize_t	bytes;

	while (*count2 < info[0].num_lines)
	{
		bytes = read(info[0].file_desc, buffer, 1);
		while (buffer[0] != '\n')
		{
			if ((buffer[0] != info[0].obst && buffer[0] != info[0].empty)
				|| bytes == 0)
				return (1);
			bytes = read(info[0].file_desc, buffer, 1);
			*count = *count +1;
		}
		if (*count != info[0].num_cols -1 || bytes == 0)
			return (1);
		*count = 0;
		*count2 = *count2 +1;
	}
	return (0);
}

int	get_map_info(char *buffer, t_mi *info)
{
	int		count;
	int		count2;
	ssize_t	bytes;

	info[0].line1[14] = 0;
	count = 0;
	if (first_line_data(buffer, &count, info) == 1)
		return (1);
	if (check_chars_first_line(info) == 1)
		return (1);
	count2 = 0;
	if (atoi_measure(buffer, &count, &count2, info) == 1)
		return (1);
	count2 = 1;
	info[0].num_cols = count;
	count = 0;
	if (check_chars_map(buffer, &count, &count2, info) == 1)
		return (1);
	bytes = read(info[0].file_desc, buffer, 1);
	if (count2 != info[0].num_lines || info[0].num_lines == 0
		|| info[0].num_cols == 0 || bytes != 0)
		return (1);
	close(info[0].file_desc);
	return (0);
}
