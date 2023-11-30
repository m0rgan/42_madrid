/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_cols_cases_3x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 18:28:05 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	l_cols_32(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 3)
	{
		if (data[c + 4] == 2)
		{
			if (matrix[1][c] == 2 || matrix[3][c] == 3)
			{
				matrix[0][c] = 1;
				matrix[1][c] = 2;
				matrix[3][c] = 3;
			}
			if ((matrix[0][c] == 1 && matrix[1][c] == 3) || matrix[3][c] == 2)
			{
				matrix[0][c] = 1;
				matrix[1][c] = 3;
				matrix[3][c] = 2;
			}
			if (matrix[0][c] == 2 || matrix[3][c] == 1)
			{
				matrix[0][c] = 2;
				matrix[1][c] = 3;
				matrix[3][c] = 1;
			}
		}
	}
	return (0);
}

int	l_cols_31(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 3)
	{
		if (data[c + 4] == 1)
		{
			if (matrix[0][c] == 1 || matrix[2][c] == 2)
			{
				matrix[0][c] = 1;
				matrix[1][c] = 3;
				matrix[2][c] = 2;
			}
			if (matrix[1][c] == 1 || matrix[2][c] == 3)
			{
				matrix[0][c] = 2;
				matrix[1][c] = 1;
				matrix[2][c] = 3;
			}
			if ((matrix[0][c] == 2 && matrix[1][c] == 3) || matrix[2][c] == 1)
			{
				matrix[0][c] = 2;
				matrix[1][c] = 3;
				matrix[2][c] = 1;
			}
		}
	}
	return (0);
}
