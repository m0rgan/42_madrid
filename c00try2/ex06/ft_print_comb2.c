/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:29:41 by migumore          #+#    #+#             */
/*   Updated: 2023/11/17 14:52:54 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digits(int *i, int *j);

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (i < j)
			{
				print_digits(&i, &j);
			}
			j++;
		}
		i++;
	}
}

void	print_digits(int *i, int *j)
{
	char	c;

	c = '0' + *i / 10;
	write(1, &c, 1);
	c = '0' + *i % 10;
	write(1, &c, 1);
	write(1, " ", 1);
	c = '0' + *j / 10;
	write(1, &c, 1);
	c = '0' + *j % 10;
	write(1, &c, 1);
	if (! (*i == 98 && *j == 99))
	{
		write(1, ", ", 2);
	}
}
