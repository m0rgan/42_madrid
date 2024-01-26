/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cols_cases_2x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:49:38 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 19:49:00 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_cols_23(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 3)
		{
			if (matrix[1][c] != 4 && matrix[1][c] != 0)
				return (1);
			matrix[1][c] = 4;
		}
	}
	return (0);
}

int	f_cols_21(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 1)
		{
			if (matrix[0][c] != 3 && matrix[0][c] != 0)
				return (1);
			matrix[0][c] = 3;
			if (matrix[3][c] != 4 && matrix[3][c] != 0)
				return (1);
			matrix[3][c] = 4;
		}
	}
	return (0);
}
