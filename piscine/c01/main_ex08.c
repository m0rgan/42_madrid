/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex08.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:29:28 by migumore          #+#    #+#             */
/*   Updated: 2023/11/15 13:27:18 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	tab[] = {2, 3, 1, 5, 6, 4};
	int	size;
	int	i;

	size = 6;
	i = 0;
	ft_sort_int_tab(tab, size);
	while (i < size)
	{
		printf("%i ", tab[i]);
		i++;
	}
	return (0);
}
