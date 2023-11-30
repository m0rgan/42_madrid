/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_rows_cases_22.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 18:21:37 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	l_rows_1_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if (mat[c - 8][0] == 1 || mat[c - 8][2] == 2)
			{
				mat[c - 8][0] = 1;
				mat[c - 8][1] = 4;
				mat[c - 8][2] = 2;
				mat[c - 8][3] = 3;
			}
			if (mat[c - 8][1] == 2 || mat[c - 8][3] == 1)
			{
				mat[c - 8][0] = 3;
				mat[c - 8][1] = 2;
				mat[c - 8][2] = 4;
				mat[c - 8][3] = 1;
			}
		}
	}
	return (0);
}

int	l_rows_2_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if ((mat[c - 8][0] == 2 && mat[c - 8][1] == 1) ||
				(mat[c - 8][0] == 2 && mat[c - 8][2] == 4) ||
				(mat[c - 8][1] == 1 && mat[c - 8][3] == 3) ||
				(mat[c - 8][2] == 4 && mat[c - 8][3] == 3))
			{
				mat[c - 8][0] = 2;
				mat[c - 8][1] = 1;
				mat[c - 8][2] = 4;
				mat[c - 8][3] = 3;
			}
		}
	}
	return (0);
}

int	l_rows_3_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if ((mat[c - 8][0] == 2 && mat[c - 8][1] == 4) ||
				(mat[c - 8][0] == 2 && mat[c - 8][2] == 1) ||
				(mat[c - 8][2] == 1 && mat[c - 8][3] == 3))
			{
				mat[c - 8][0] = 2;
				mat[c - 8][1] = 4;
				mat[c - 8][2] = 1;
				mat[c - 8][3] = 3;
			}
		}
	}
	return (0);
}

int	l_rows_4_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if ((mat[c - 8][0] == 3 && mat[c - 8][1] == 4) ||
				(mat[c - 8][0] == 3 && mat[c - 8][2] == 1) ||
				(mat[c - 8][1] == 4 && mat[c - 8][3] == 2) ||
				(mat[c - 8][2] == 1 && mat[c - 8][3] == 2))
			{
				mat[c - 8][0] = 3;
				mat[c - 8][1] = 4;
				mat[c - 8][2] = 1;
				mat[c - 8][3] = 2;
			}
		}
	}
	return (0);
}

int	l_rows_5_22(int mat[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 2)
		{
			if ((mat[c - 8][0] == 3 && mat[c - 8][1] == 1) ||
				(mat[c - 8][1] == 1 && mat[c - 8][3] == 2) ||
				(mat[c - 8][2] == 4 && mat[c - 8][3] == 2))
			{
				mat[c - 8][0] = 3;
				mat[c - 8][1] = 1;
				mat[c - 8][2] = 4;
				mat[c - 8][3] = 2;
			}
		}
	}
	return (0);
}
