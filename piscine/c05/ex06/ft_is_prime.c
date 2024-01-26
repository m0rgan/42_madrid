/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:31:19 by migumore          #+#    #+#             */
/*   Updated: 2023/11/30 20:09:51 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	start;
	int	mid;
	int	end;

	if (nb < 2)
		return (nb);
	start = 2;
	end = nb / 2;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (nb / mid < mid)
			end = mid - 1;
		else if (nb / mid > mid)
			start = mid + 1;
		else
			return (mid);
	}
	return (start);
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
