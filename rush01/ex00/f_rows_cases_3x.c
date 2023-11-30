/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rows_cases_3x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 15:54:47 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_rows_32(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 3)
	{
		if (data[c + 4] == 2)
		{
			if (matrix[c - 8][2] != 4 && matrix[c - 8][2] != 0)
				return (1);
			matrix[c - 8][2] = 4;
		}
	}
	return (0);
}

int	f_rows_31(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 3)
	{
		if (data[c + 4] == 1)
		{
			if (matrix[c - 8][3] != 4 && matrix[c - 8][3] != 0)
				return (1);
			matrix[c - 8][3] = 4;
		}
	}
	return (0);
}
