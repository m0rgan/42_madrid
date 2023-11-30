/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rows_cases_1x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 15:54:25 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_rows_14(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 1)
	{
		if (data[c + 4] == 4)
		{
			if (matrix[c - 8][0] != 4 && matrix[c - 8][0] != 0)
				return (1);
			matrix[c - 8][0] = 4;
			if (matrix[c - 8][1] != 3 && matrix[c - 8][1] != 0)
				return (1);
			matrix[c - 8][1] = 3;
			if (matrix[c - 8][2] != 2 && matrix[c - 8][2] != 0)
				return (1);
			matrix[c - 8][2] = 2;
			if (matrix[c - 8][3] != 1 && matrix[c - 8][3] != 0)
				return (1);
			matrix[c - 8][3] = 1;
		}
	}
	return (0);
}

int	f_rows_13(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 1)
	{
		if (data[c + 4] == 3)
		{
			if (matrix[c - 8][0] != 4 && matrix[c - 8][0] != 0)
				return (1);
			matrix[c - 8][0] = 4;
		}
	}
	return (0);
}

int	f_rows_12(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 1)
	{
		if (data[c + 4] == 2)
		{
			if (matrix[c - 8][0] != 4 && matrix[c - 8][0] != 0)
				return (1);
			matrix[c - 8][0] = 4;
			if (matrix[c - 8][3] != 3 && matrix[c - 8][3] != 0)
				return (1);
			matrix[c - 8][3] = 3;
		}
	}
	return (0);
}
