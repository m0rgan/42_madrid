/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cols_cases_3x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:55:30 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 18:26:45 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_cols_32(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 3)
	{
		if (data[c + 4] == 2)
		{
			if (matrix[2][c] != 4 && matrix[2][c] != 0)
				return (1);
			matrix[2][c] = 4;
		}
	}
	return (0);
}

int	f_cols_31(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 3)
	{
		if (data[c + 4] == 1)
		{
			if (matrix[3][c] != 4 && matrix[3][c] != 0)
				return (1);
			matrix[3][c] = 4;
		}
	}
	return (0);
}
