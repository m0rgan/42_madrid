/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:53:51 by migumore          #+#    #+#             */
/*   Updated: 2023/11/12 20:48:46 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	top_bottom_line(int x);
void	inside_line(int x);
int		check_errors(int x, int y);

void	rush(int x, int y)
{
	int	count;

	count = 0;
	if (check_errors(x, y) == 1)
	{
		write(1, "Error", 5);
	}
	else
	{
		while (count < y)
		{
			if (count == 0 || count == y - 1)
			{
				top_bottom_line(x);
			}
			else
			{
				inside_line(x);
			}
			count++;
		}
	}
}

void	top_bottom_line(int x)
{
	int	count;

	count = 0;
	while (count < x)
	{
		if (count == 0 || count == x - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		count++;
	}
	ft_putchar('\n');
}

void	inside_line(int x)
{
	int	count;

	count = 0;
	while (count < x)
	{
		if (count == 0 || count == x - 1)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
		count++;
	}
	ft_putchar('\n');
}

int	check_errors(int x, int y)
{
	if (x < 1)
	{
		return (1);
	}
	if (y < 1)
	{
		return (1);
	}
	return (0);
}
