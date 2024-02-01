/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:08:25 by migumore          #+#    #+#             */
/*   Updated: 2024/02/01 15:04:24 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*content;

	fd = open("./text", O_RDONLY);
	while (content)
	{
		content = get_next_line(fd);
		if (content == NULL)
		{
			printf("Error reading file");
			return (1);
		}
		printf("%s", content);
		free(content);
	}
	free(content);
	close(fd);
	return (0);
}
