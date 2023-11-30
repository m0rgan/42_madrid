/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:27:31 by migumore          #+#    #+#             */
/*   Updated: 2023/11/15 13:27:41 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	count1;
	int	count2;

	count1 = 0;
	while (count1 < size)
	{
		count2 = 0;
		while (count2 < size)
		{
			if (tab[count1] < tab[count2])
			{
				temp = tab[count1];
				tab[count1] = tab[count2];
				tab[count2] = temp;
			}
			count2++;
		}
		count1++;
	}
}
