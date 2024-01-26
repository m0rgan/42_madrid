/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rows_cases_4x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:38:18 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 15:55:08 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_rows_41(int matrix[4][4], int c, int data[16])
{
	if (data[c] == 4)
	{
		if (data[c + 4] == 1)
		{
			if (matrix[c - 8][0] != 1 && matrix[c - 8][0] != 0)
				return (1);
			matrix[c - 8][0] = 1;
			if (matrix[c - 8][1] != 2 && matrix[c - 8][1] != 0)
				return (1);
			matrix[c - 8][1] = 2;
			if (matrix[c - 8][2] != 3 && matrix[c - 8][2] != 0)
				return (1);
			matrix[c - 8][2] = 3;
			if (matrix[c - 8][3] != 4 && matrix[c - 8][3] != 0)
				return (1);
			matrix[c - 8][3] = 4;
		}
	}
	return (0);
}
