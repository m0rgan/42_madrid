/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_def.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:46:07 by migumore          #+#    #+#             */
/*   Updated: 2023/11/26 15:24:42 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_thousand(int nb)
{
	int	i;

	i = 1010;
	while (i <= 10000 && nb >= 1000)
	{
		if (nb >= i && nb < i + 10)
			return (i);
		i += 10;
	}
	return (10000);
}

int	is_hundred(int nb)
{
	int	i;

	i = 110;
	if (nb > 1000)
		return (is_thousand(nb));
	while (i <= 1000 && nb >= 100)
	{
		if (nb >= i && nb < i + 10)
			return (i);
		i += 10;
	}
	return (1000);
}

int	is_ten(int nb)
{
	int	i;

	i = 20;
	if (nb > 100)
		return (is_hundred(nb));
	while (i <= 100 && nb >= 10)
	{
		if (nb >= i && nb < i + 10)
			return (i);
		i += 10;
	}
	return (nb);
}
