/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:08:25 by migumore          #+#    #+#             */
/*   Updated: 2024/02/02 16:45:06 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*content;
	int		i;

	i = 0;
	fd = open("./text", O_RDONLY);
	while (i < 5)
	{
		content = get_next_line(fd);
		printf("%s", content);
		i++;
	}
	free(content);
	close(fd);
	system("leaks a.out");
	return (0);
}
