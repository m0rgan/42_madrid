/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_rows_cases_2x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 18:29:33 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		l_rows_1_22(int mat[4][4], int c, int data[16]);
int		l_rows_2_22(int mat[4][4], int c, int data[16]);
int		l_rows_3_22(int mat[4][4], int c, int data[16]);
int		l_rows_4_22(int mat[4][4], int c, int data[16]);
int		l_rows_5_22(int mat[4][4], int c, int data[16]);

int	l_rows_23(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 3)
		{
			if (mat[c -8][0] == 3 || mat[c -8][2] == 2)
			{
				mat[c -8][0] = 3;
				mat[c -8][2] = 2;
				mat[c -8][3] = 1;
			}
			if (mat[c -8][0] == 2 || (mat[c -8][2] == 3 && mat[c -8][3] == 1))
			{
				mat[c -8][0] = 2;
				mat[c -8][2] = 3;
				mat[c -8][3] = 1;
			}
			if (mat[c -8][0] == 1 || mat[c -8][3] == 2)
			{
				mat[c -8][0] = 1;
				mat[c -8][2] = 3;
				mat[c -8][3] = 2;
			}
		}
	}
	return (0);
}

int	l_rows_22(int matrix[4][4], int c, int data[16])
{
	if (l_rows_1_22(matrix, c, data) == 1)
		return (1);
	if (l_rows_2_22(matrix, c, data) == 1)
		return (1);
	if (l_rows_3_22(matrix, c, data) == 1)
		return (1);
	if (l_rows_4_22(matrix, c, data) == 1)
		return (1);
	if (l_rows_5_22(matrix, c, data) == 1)
		return (1);
	return (0);
}

int	l_rows_21(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 1)
		{
			if (mat[c -8][1] == 1 || mat[c -8][2] == 2)
			{
				mat[c -8][1] = 1;
				mat[c -8][2] = 2;
			}
			if (mat[c -8][1] == 2 || mat[c -8][2] == 1)
			{
				mat[c -8][1] = 2;
				mat[c -8][2] = 1;
			}
		}
	}
	return (0);
}
