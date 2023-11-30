/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:07 by migumore          #+#    #+#             */
/*   Updated: 2023/11/28 16:31:43 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb == 0)
		return (1);
	else if (nb > 0)
	{
		nb--;
		while (nb >= 1)
		{
			result *= nb;
			nb--;
		}
		return (result);
	}
	return (0);
}
