/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:38:48 by migumore          #+#    #+#             */
/*   Updated: 2023/11/30 20:03:45 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	start;
	int	mid;
	int	end;

	if (nb < 0)
		return (0);
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
	return (0);
}
