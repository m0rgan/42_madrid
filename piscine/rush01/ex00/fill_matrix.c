/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:39:45 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 20:02:17 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		f_cols_14(int matrix[4][4], int c, int data[16]);
int		f_cols_13(int matrix[4][4], int c, int data[16]);
int		f_cols_12(int matrix[4][4], int c, int data[16]);
int		f_cols_23(int matrix[4][4], int c, int data[16]);
int		f_cols_21(int matrix[4][4], int c, int data[16]);
int		f_cols_32(int matrix[4][4], int c, int data[16]);
int		f_cols_31(int matrix[4][4], int c, int data[16]);
int		f_cols_41(int matrix[4][4], int c, int data[16]);
int		f_rows_14(int matrix[4][4], int c, int data[16]);
int		f_rows_13(int matrix[4][4], int c, int data[16]);
int		f_rows_12(int matrix[4][4], int c, int data[16]);
int		f_rows_23(int matrix[4][4], int c, int data[16]);
int		f_rows_21(int matrix[4][4], int c, int data[16]);
int		f_rows_32(int matrix[4][4], int c, int data[16]);
int		f_rows_31(int matrix[4][4], int c, int data[16]);
int		f_rows_41(int matrix[4][4], int c, int data[16]);
int		l_cols_13(int matrix[4][4], int c, int data[16]);
int		l_cols_12(int matrix[4][4], int c, int data[16]);
int		l_cols_23(int matrix[4][4], int c, int data[16]);
int		l_cols_22(int matrix[4][4], int c, int data[16]);
int		l_cols_21(int matrix[4][4], int c, int data[16]);
int		l_cols_32(int matrix[4][4], int c, int data[16]);
int		l_cols_31(int matrix[4][4], int c, int data[16]);
int		l_rows_13(int matrix[4][4], int c, int data[16]);
int		l_rows_12(int matrix[4][4], int c, int data[16]);
int		l_rows_23(int matrix[4][4], int c, int data[16]);
int		l_rows_22(int matrix[4][4], int c, int data[16]);
int		l_rows_21(int matrix[4][4], int c, int data[16]);
int		l_rows_32(int matrix[4][4], int c, int data[16]);
int		l_rows_31(int matrix[4][4], int c, int data[16]);

int	fill_forced_cols(int matrix[4][4], int data[16])
{
	int	c;

	c = 0;
	while (c <= 3)
	{
		if (f_cols_14(matrix, c, data) == 1)
			return (1);
		if (f_cols_13(matrix, c, data) == 1)
			return (1);
		if (f_cols_12(matrix, c, data) == 1)
			return (1);
		if (f_cols_23(matrix, c, data) == 1)
			return (1);
		if (f_cols_21(matrix, c, data) == 1)
			return (1);
		if (f_cols_32(matrix, c, data) == 1)
			return (1);
		if (f_cols_31(matrix, c, data) == 1)
			return (1);
		if (f_cols_41(matrix, c, data) == 1)
			return (1);
		c++;
	}
	return (0);
}

int	fill_forced_rows(int matrix[4][4], int data[16])
{
	int	c;

	c = 8;
	while (c <= 11)
	{
		if (f_rows_14(matrix, c, data) == 1)
			return (1);
		if (f_rows_13(matrix, c, data) == 1)
			return (1);
		if (f_rows_12(matrix, c, data) == 1)
			return (1);
		if (f_rows_23(matrix, c, data) == 1)
			return (1);
		if (f_rows_21(matrix, c, data) == 1)
			return (1);
		if (f_rows_32(matrix, c, data) == 1)
			return (1);
		if (f_rows_31(matrix, c, data) == 1)
			return (1);
		if (f_rows_41(matrix, c, data) == 1)
			return (1);
		c++;
	}
	return (0);
}

int	fill_logic_cols(int matrix[4][4], int data[16])
{
	int	c;

	c = 0;
	while (c <= 3)
	{
		if (l_cols_13(matrix, c, data) == 1)
			return (1);
		if (l_cols_12(matrix, c, data) == 1)
			return (1);
		if (l_cols_23(matrix, c, data) == 1)
			return (1);
		if (l_cols_22(matrix, c, data) == 1)
			return (1);
		if (l_cols_21(matrix, c, data) == 1)
			return (1);
		if (l_cols_32(matrix, c, data) == 1)
			return (1);
		if (l_cols_31(matrix, c, data) == 1)
			return (1);
		c++;
	}
	return (0);
}

int	fill_logic_rows(int matrix[4][4], int data[16])
{
	int	c;

	c = 8;
	while (c <= 11)
	{
		if (l_rows_13(matrix, c, data) == 1)
			return (1);
		if (l_rows_12(matrix, c, data) == 1)
			return (1);
		if (l_rows_23(matrix, c, data) == 1)
			return (1);
		if (l_rows_22(matrix, c, data) == 1)
			return (1);
		if (l_rows_21(matrix, c, data) == 1)
			return (1);
		if (l_rows_32(matrix, c, data) == 1)
			return (1);
		if (l_rows_31(matrix, c, data) == 1)
			return (1);
		c++;
	}
	return (0);
}
