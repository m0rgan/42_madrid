/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:14:37 by migumore          #+#    #+#             */
/*   Updated: 2024/01/28 12:19:36 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello!", ' ');
	i = 0;
	while (words[i] != NULL)
	{
		printf("%s\n", words[i]);
		i++;
	}
	return (0);
}
