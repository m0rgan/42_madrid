/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:00:51 by migumore          #+#    #+#             */
/*   Updated: 2023/11/29 18:40:40 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

void	solver(int np, char **argv)
{
	int		count;

	count = 1;
	while (count < np)
	{
		if (read_file(argv[count]) != 0)
		{
			write (2, "map error\n", 10);
			return ;
		}
		if (count != np -1)
			write (1, "\n", 1);
		count ++;
	}
}

int	main(int np, char **argv)
{
	char	buffer[50];
	ssize_t	bytes;

	if (np == 1)
	{
		bytes = read(0, buffer, 50);
		buffer[bytes -1] = 0;
		if (read_file(buffer) != 0)
		{
			write (2, "map error\n", 10);
		}
		return (0);
	}
	if (np >= 2)
		solver(np, argv);
	return (0);
}
