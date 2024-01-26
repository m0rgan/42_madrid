/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:03:28 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/01/23 12:54:10 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map_info
{
	int		file_desc;
	int		num_lines;
	int		num_cols;
	int		line1_size;
	char	empty;
	char	obst;
	char	full;
	char	**map;
	int		**sol_map;
	int		sol_x;
	int		sol_y;
	int		sol_value;
	char	line1[15];
}	t_mi;

void	solver(int np, char **argv);
void	print_map(t_mi *info);
void	extract_map(char *file, t_mi *map_info);
int		read_file(char *file);
int		get_map_info(char *buffer, t_mi *info);
void	logic(t_mi *map_info);
void	replace_map(t_mi *info);
int		file_valid(char *buffer, t_mi *map_info);
void	free_memory(t_mi *map_info);

#endif