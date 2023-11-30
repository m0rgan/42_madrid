/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:18:43 by migumore          #+#    #+#             */
/*   Updated: 2023/11/24 12:25:32 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base)
{
	int	count;

	count = 0;
	while (base[count])
	{
		count++;
	}
	return (count);
}

int	ft_base_ok(char *base)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = count1 + 1;
	while (base[count1])
	{
		count2 = count1 + 1;
		while (base[count2])
		{
			if (base[count1] == base[count2]
				|| base[count2] == '+'
				|| base[count2] == '-')
				return (1);
			count2++;
		}
		count1++;
	}
	return (0);
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
	int		length;
	int		base_ok;
	long	nb;

	length = ft_strlen(base);
	base_ok = ft_base_ok(base);
	nb = nbr;
	if (length > 1 && base_ok == 0)
		ft_putnbr(nb, length, base);
}
