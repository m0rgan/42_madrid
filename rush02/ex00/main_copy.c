/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:17:00 by dgargant          #+#    #+#             */
/*   Updated: 2023/11/26 18:49:20 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy();

int	main(void)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		fd;
	char	buf[700];
	char 	copy[41][12];
	ssize_t nr_bytes;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error al abrir el archivo", 25);
	}
	else
	{
		nr_bytes = read(fd, buf, 700);
		close(fd);
		if (nr_bytes == 0)
		{
			write(1, "Archivo vacio", 13);
		}
		else
		{
			while (buf[i] != '\0')
			{
				if (buf[i] >= 'a' && buf[i] <= 'z')
				{
					copy[j][k] = buf[i];
					k++;
				}
				if (buf[i] == '\n')
				{
					copy[j][k] = '\0';
					j++;
					k = 0;
				}
				i++;
			}
		}
	}
	return (0);
}
