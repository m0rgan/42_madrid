/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:50:01 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 17:24:26 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	val_1(int data[16], int *c1, int count)
{
	if (data[count -1] == 1)
	{
		if (*c1 == 2)
			return (1);
		*c1 = *c1 + 1;
	}
	return (0);
}

int	val_2(int data[16], int *c2, int count)
{
	if (data[count -1] == 2)
	{
		if (*c2 == 4)
			return (1);
		*c2 = *c2 + 1;
	}
	return (0);
}

int	val_3(int data[16], int *c3, int count)
{
	if (data[count -1] == 3)
	{
		if (*c3 == 3)
			return (1);
		*c3 = *c3 + 1;
	}
	return (0);
}

int	val_4(int data[16], int *c4, int count)
{
	if (data[count -1] == 4)
	{
		if (*c4 == 1)
			return (1);
		*c4 = *c4 + 1;
	}
	return (0);
}
