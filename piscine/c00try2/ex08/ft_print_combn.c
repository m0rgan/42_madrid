/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:08:11 by migumore          #+#    #+#             */
/*   Updated: 2023/11/20 12:22:04 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combinations(char *comb, int start_digit, int n, int original_n);

static int	g_first_combination = 1;

void	ft_print_combn(int n)
{
	char	comb[10];

	print_combinations(comb, 0, n, n);
	g_first_combination = 1;
}

void	print_combinations(char *comb, int start_digit, int n, int original_n)
{
	int	i;

	i = start_digit;
	if (n == 0)
	{
		if (g_first_combination == 0)
		{
			write(1, ", ", 2);
		}
		comb[original_n] = '\0';
		write(1, comb, original_n);
		g_first_combination = 0;
	}
	else
	{
		while (i <= 9)
		{
			comb[original_n - n] = '0' + i;
			print_combinations(comb, i + 1, n - 1, original_n);
			i++;
		}
	}
}
