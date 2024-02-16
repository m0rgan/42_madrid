/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:41:44 by migumore          #+#    #+#             */
/*   Updated: 2024/02/09 11:44:48 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;

	printf("Reading lines from stdin:\n");
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		printf("Line read: %s", line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (0);
}
