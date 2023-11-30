/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cols_cases_4x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:55:30 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 15:54:16 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_cols_41(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 4)
	{
		if (data[c + 4] == 1)
		{
			if (matrix[0][c] != 1 && matrix[0][c] != 0)
				return (1);
			matrix[0][c] = 1;
			if (matrix[1][c] != 2 && matrix[1][c] != 0)
				return (1);
			matrix[1][c] = 2;
			if (matrix[2][c] != 3 && matrix[2][c] != 0)
				return (1);
			matrix[2][c] = 3;
			if (matrix[3][c] != 4 && matrix[3][c] != 0)
				return (1);
			matrix[3][c] = 4;
		}
	}
	return (0);
}
