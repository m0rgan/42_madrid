/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_migumore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:45:10 by migumore          #+#    #+#             */
/*   Updated: 2023/11/26 15:18:58 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		is_ten(int nb);

int	main(int np, char *argv[])
{
	char	*str;
	int		nb;
	int		i;
	int		num_range;

	str = malloc(ft_strlen(argv[1]) + 1);
	nb = 0;
	i = 0;
	num_range = 0;
	if (np == 2)
	{
		str = ft_strcpy(str, argv[1]);
		nb = ft_atoi(str);
		num_range = is_ten(nb);
		printf("%i\n", nb);
		printf("%i\n", num_range);
	}
	return (0);
}
