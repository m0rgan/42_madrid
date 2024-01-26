/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:26:20 by dgomez-l          #+#    #+#             */
/*   Updated: 2023/11/21 09:49:41 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_matrix(int matrix[4][4]);
int		fill_forced_cols(int matrix[4][4], int data[16]);
int		fill_forced_rows(int matrix[4][4], int data[16]);
int		fill_logic_cols(int matrix[4][4], int data[16]);
int		fill_logic_rows(int matrix[4][4], int data[16]);

void	fill_with_zeros(int matrix[4][4])
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (rows <= 3)
	{
		while (cols <= 3)
		{
			matrix[rows][cols] = 0;
			cols++;
		}
		cols = 0;
		rows++;
	}
}

int	fill_matrix_forced(int data[16], int matrix[4][4])
{
	if (fill_forced_cols(matrix, data) == 1)
		return (1);
	if (fill_forced_rows(matrix, data) == 1)
		return (1);
	return (0);
}

int	fill_matrix_logic(int data[16], int matrix[4][4])
{
	if (fill_logic_cols(matrix, data) == 1)
		return (1);
	if (fill_logic_rows(matrix, data) == 1)
		return (1);
	return (0);
}

void	fill_with_one_where_zeros(int matrix[4][4])
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (rows <= 3)
	{
		while (cols <= 3)
		{
			if (matrix[rows][cols] == 0)
				matrix[rows][cols] = 1;
			cols++;
		}
		cols = 0;
		rows++;
	}
}

int	solver(int data[16], int matrix[4][4])
{
	int	i;

	i = 0;
	fill_with_zeros(matrix);
	if (fill_matrix_forced(data, matrix) != 0)
		return (1);
	while (i < 10)
	{
		if (fill_matrix_logic(data, matrix) != 0)
			return (1);
		if (i == 5)
			fill_with_one_where_zeros(matrix);
		i++;
	}
	return (0);
}
