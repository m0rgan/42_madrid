/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:47:09 by dgomez-l          #+#    #+#             */
/*   Updated: 2023/11/22 13:51:02 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
*/

int	data_validation(char *args, int *final_data)
{
	int		cnt_f;
	int		cnt_r;
	int		control_1;

	cnt_f = 0;
	cnt_r = 0;
	control_1 = 0;
	while (cnt_r < 31)
	{
		if (cnt_r % 2 == 0)
		{
			if (args[cnt_r] < '1' || args[cnt_r] > '4')
				return (1);
			final_data[cnt_f] = args[cnt_r] -48;
			cnt_f ++;
		}
		else if (args[cnt_r] != ' ' || args[cnt_r] == '\0')
			return (1);
		cnt_r ++;
	}
	if (args[31] != '\0')
		return (1);
	return (0);
}

int	val_values(int data[16], int count)
{
	if (data[count] == 4)
	{
		if (data[count +4] != 1)
			return (1);
	}
	if (data[count] == 3)
	{
		if (data[count +4] == 4 || data[count +4] == 3)
			return (1);
	}
	if (data[count] == 2)
	{
		if (data[count +4] == 4)
			return (1);
	}
	if (data[count] == 1)
	{
		if (data[count +4] == 1)
			return (1);
	}
	return (0);
}

int	val_rows(int data[16])
{
	int	count;

	count = 0;
	while (count <= 3)
	{
		if (val_values(data, count) == 1)
			return (1);
		count ++;
	}
	return (0);
}

int	val_cols(int data[16])
{
	int	count;

	count = 8;
	while (count <= 11)
	{
		if (val_values(data, count) == 1)
			return (1);
		count ++;
	}
	return (0);
}
