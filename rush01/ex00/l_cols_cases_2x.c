/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_cols_cases_2x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 18:29:20 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		l_cols_1_22(int mat[4][4], int c, int data[16]);
int		l_cols_2_22(int mat[4][4], int c, int data[16]);
int		l_cols_3_22(int mat[4][4], int c, int data[16]);
int		l_cols_4_22(int mat[4][4], int c, int data[16]);
int		l_cols_5_22(int mat[4][4], int c, int data[16]);

int	l_cols_23(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 3)
		{
			if (matrix[0][c] == 3 || matrix[2][c] == 2)
			{
				matrix[0][c] = 3;
				matrix[2][c] = 2;
				matrix[3][c] = 1;
			}
			if (matrix[0][c] == 2 || (matrix[2][c] == 3 && matrix[3][c] == 1))
			{
				matrix[0][c] = 2;
				matrix[2][c] = 3;
				matrix[3][c] = 1;
			}
			if (matrix[0][c] == 1 || matrix[3][c] == 2)
			{
				matrix[0][c] = 1;
				matrix[2][c] = 3;
				matrix[3][c] = 2;
			}
		}
	}
	return (0);
}

int	l_cols_22(int matrix[4][4], int c, int data[16])
{
	if (l_cols_1_22(matrix, c, data) == 1)
		return (1);
	if (l_cols_2_22(matrix, c, data) == 1)
		return (1);
	if (l_cols_3_22(matrix, c, data) == 1)
		return (1);
	if (l_cols_4_22(matrix, c, data) == 1)
		return (1);
	if (l_cols_5_22(matrix, c, data) == 1)
		return (1);
	return (0);
}

int	l_cols_21(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 1)
		{
			if (matrix[1][c] == 1 || matrix[2][c] == 2)
			{
				matrix[1][c] = 1;
				matrix[2][c] = 2;
			}
			if (matrix[1][c] == 2 || matrix[2][c] == 1)
			{
				matrix[1][c] = 2;
				matrix[2][c] = 1;
			}
		}
	}
	return (0);
}
