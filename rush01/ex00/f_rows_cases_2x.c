/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rows_cases_2x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 19:49:04 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_rows_23(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 3)
		{
			if (matrix[c - 8][1] != 4 && matrix[c - 8][1] != 0)
				return (1);
			matrix[c - 8][1] = 4;
		}
	}
	return (0);
}

int	f_rows_21(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 2)
	{
		if (data[c + 4] == 1)
		{
			if (matrix[c - 8][0] != 3 && matrix[c - 8][0] != 0)
				return (1);
			matrix[c - 8][0] = 3;
			if (matrix[c - 8][3] != 4 && matrix[c - 8][3] != 0)
				return (1);
			matrix[c - 8][3] = 4;
		}
	}
	return (0);
}
