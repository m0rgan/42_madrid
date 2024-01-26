/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:26:45 by migumore          #+#    #+#             */
/*   Updated: 2023/11/16 15:54:22 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[] = "Hello";
	char dest[] = "World1";
	char *result;

	result = ft_strncpy(dest, src, 7);
	printf("Destination: %s\n", result);
	return (0);
}
