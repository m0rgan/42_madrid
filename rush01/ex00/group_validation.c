/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:33:33 by migumore          #+#    #+#             */
/*   Updated: 2023/11/19 17:22:58 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	val_1(int data[16], int *c1, int count);
int	val_2(int data[16], int *c2, int count);
int	val_3(int data[16], int *c3, int count);
int	val_4(int data[16], int *c4, int count);

static int	g_count = 1;

int	count_val(int *c1, int *c2, int *c3, int *c4)
{
	int	sum;

	sum = *c1 + *c2 * 2 + *c3 * 3 + *c4 * 4;
	if (g_count % 4 == 0)
	{
		if (*c1 != 1)
			return (1);
		if (sum < 7 || sum > 10)
			return (1);
		*c1 = 0;
		*c2 = 0;
		*c3 = 0;
		*c4 = 0;
	}
	return (0);
}

int	val_groups(int data[16])
{
	int		c1;
	int		c2;
	int		c3;
	int		c4;

	c1 = 0;
	c2 = 0;
	c3 = 0;
	c4 = 0;
	while (g_count <= 16)
	{
		if (val_1(data, &c1, g_count) == 1)
			return (1);
		if (val_2(data, &c2, g_count) == 1)
			return (1);
		if (val_3(data, &c3, g_count) == 1)
			return (1);
		if (val_4(data, &c4, g_count) == 1)
			return (1);
		count_val(&c1, &c2, &c3, &c4);
		g_count ++;
	}
	return (0);
}
