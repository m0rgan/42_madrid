/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:14:11 by dgomez-l          #+#    #+#             */
/*   Updated: 2023/11/21 09:33:00 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		data_validation(char *args, int *final_data);
int		val_rows(int data[16]);
int		val_cols(int data[16]);
int		val_groups(int data[16]);
int		solver(int data[16], int matrix[4][4]);
void	print_matrix(int matrix[4][4]);

int	main(int np, char **args)
{
	int		data[4 * 4];
	int		matrix[4][4];

	if (np != 2)
	{
		write (2, "Error\n", 7);
		return (1);
	}
	if (data_validation(args[1], &data[0]) != 0)
	{
		write (2, "Error\n", 7);
		return (1);
	}
	if (val_rows(data) != 0 || val_cols(data) != 0 || val_groups(data) != 0)
	{
		write (2, "Error\n", 7);
		return (1);
	}
	if (solver(data, matrix) != 0)
	{
		write (2, "Error\n", 7);
		return (1);
	}
	print_matrix(matrix);
	return (0);
}
