/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:45:10 by migumore          #+#    #+#             */
/*   Updated: 2023/11/26 19:43:34 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_dictionary(char *buf);
char	*ft_num_letters(char *buf, int p);

int	main(int np, char *argv[])
{
	char	*str;
	int		nb;
	int		i;
	char	*buf[700];

	str = malloc(ft_strlen(argv[1]) + 1);
	nb = 0;
	i = 0;
	if (np == 2)
	{
		str = ft_strcpy(str, argv[1]);
		nb = ft_atoi(str);
		ft_num_letters(ft_dictionary(*buf), nb);
	}
	else
		write(1, "error", 5);
	free(str);
	return (0);
}
