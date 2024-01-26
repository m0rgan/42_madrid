/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:18:43 by migumore          #+#    #+#             */
/*   Updated: 2023/11/24 12:33:11 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_base_parameters(char *base, char params[2])
{
	int		count1;
	int		count2;

	count1 = 0;
	count2 = count1 + 1;
	params[0] = 0;
	params[1] = 0;
	while (base[count1])
	{
		count2 = count1 + 1;
		while (base[count2])
		{
			if (base[count1] == base[count2]
				|| base[count2] == '+'
				|| base[count2] == '-')
				params[0] = 1;
			count2++;
		}
		count1++;
	}
	params[1] = count1;
}

void	ft_putnbr(long nb, int length, char *base)
{
	char	d;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= length)
	{
		ft_putnbr(nb / length, length, base);
	}
	d = base[nb % length];
	write(1, &d, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	params[2];
	int		num;
	int		length;
	long	nb;

	ft_base_parameters(base, params);
	num = 0;
	length = params[1];
	nb = nbr;
	if (params[0] == 0 && length > 1)
		ft_putnbr(nb, length, base);
}
