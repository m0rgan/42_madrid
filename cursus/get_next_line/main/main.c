/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:08:25 by migumore          #+#    #+#             */
/*   Updated: 2024/01/31 14:18:35 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*content;

	fd = open("/Users/migumore/mmv/github/42_madrid/cursus/get_next_line/get_next_line/text", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	content = get_next_line(fd);
	if (content == NULL)
	{
		printf("Error reading file");
		return (1);
	}
	printf("%s", content);
	free(content);
	close(fd);
	return (0);
}
