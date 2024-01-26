/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_cols_cases_22.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 18:15:45 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	l_cols_1_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if (mat[0][c] == 1 || mat[2][c] == 2)
			{
				mat[0][c] = 1;
				mat[1][c] = 4;
				mat[2][c] = 2;
				mat[3][c] = 3;
			}
			if (mat[1][c] == 2 || mat[3][c] == 1)
			{
				mat[0][c] = 3;
				mat[1][c] = 2;
				mat[2][c] = 4;
				mat[3][c] = 1;
			}
		}
	}
	return (0);
}

int	l_cols_2_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if ((mat[0][c] == 2 && mat[1][c] == 1) ||
				(mat[0][c] == 2 && mat[2][c] == 4) ||
				(mat[1][c] == 1 && mat[3][c] == 3) ||
				(mat[2][c] == 4 && mat[3][c] == 3))
			{
				mat[0][c] = 2;
				mat[1][c] = 1;
				mat[2][c] = 4;
				mat[3][c] = 3;
			}
		}
	}
	return (0);
}

int	l_cols_3_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if ((mat[0][c] == 2 && mat[1][c] == 4) ||
				(mat[0][c] == 2 && mat[2][c] == 1) ||
				(mat[2][c] == 1 && mat[3][c] == 3))
			{
				mat[0][c] = 2;
				mat[1][c] = 4;
				mat[2][c] = 1;
				mat[3][c] = 3;
			}
		}
	}
	return (0);
}

int	l_cols_4_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if ((mat[0][c] == 3 && mat[1][c] == 4) ||
				(mat[0][c] == 3 && mat[2][c] == 1) ||
				(mat[1][c] == 4 && mat[3][c] == 2) ||
				(mat[2][c] == 1 && mat[3][c] == 2))
			{
				mat[0][c] = 3;
				mat[1][c] = 4;
				mat[2][c] = 1;
				mat[3][c] = 2;
			}
		}
	}
	return (0);
}

int	l_cols_5_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if ((mat[0][c] == 3 && mat[1][c] == 1) ||
				(mat[1][c] == 1 && mat[3][c] == 2) ||
				(mat[2][c] == 4 && mat[3][c] == 2))
			{
				mat[0][c] = 3;
				mat[1][c] = 1;
				mat[2][c] = 4;
				mat[3][c] = 2;
			}
		}
	}
	return (0);
}
