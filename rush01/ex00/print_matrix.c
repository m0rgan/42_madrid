/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:24:08 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 18:28:42 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_matrix(int matrix[4][4])
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (rows <= 3)
	{
		while (cols <= 3)
		{
			write(1, &(char){matrix[rows][cols] + '0'}, 1);
			if (cols != 3)
				write(1, " ", 1);
			cols++;
		}
		cols = 0;
		rows++;
		write(1, "\n", 1);
	}
}
