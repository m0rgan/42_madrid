/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_cols_cases_1x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 18:27:53 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	l_cols_13(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 1)
	{
		if (data[c + 4] == 3)
		{
			if (matrix[1][c] == 3 || matrix[2][c] == 1)
			{
				matrix[1][c] = 3;
				matrix[2][c] = 1;
				matrix[3][c] = 2;
			}
			if (matrix[1][c] == 2 || matrix[3][c] == 1)
			{
				matrix[1][c] = 2;
				matrix[2][c] = 3;
				matrix[3][c] = 1;
			}
			if (matrix[1][c] == 1 || (matrix[2][c] == 3 && matrix[3][c] == 2))
			{
				matrix[1][c] = 1;
				matrix[2][c] = 3;
				matrix[3][c] = 2;
			}
		}
	}
	return (0);
}

int	l_cols_12(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 1)
	{
		if (data[c + 4] == 2)
		{
			if (matrix[1][c] == 2 || matrix[2][c] == 1)
			{
				matrix[1][c] = 2;
				matrix[2][c] = 1;
			}
			if (matrix[1][c] == 1 || matrix[2][c] == 2)
			{
				matrix[1][c] = 1;
				matrix[2][c] = 2;
			}
		}
	}
	return (0);
}
