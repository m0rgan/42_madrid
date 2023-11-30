/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:17:00 by dgargant          #+#    #+#             */
/*   Updated: 2023/11/26 13:14:34 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	file_size(void)
{
	int		size;
	int		file_desc;
	int		bytes;
	char	buffer[100];

	size = 0;
	file_desc = open("numbers.dict", O_RDONLY);
	bytes = read(fd, buf, 100);
	if (fd == -1)
		return (size);
	else
	{
		bytes = read(fd, buf, 100);
		while ()
		{
		}
		bytes = read(fd, buf, );
		close(fd);
		if (nr_bytes == 0)
			return (size);
	}
}

char	*dictionary(void)
{
	char	*buffer;

	buffer = malloc(file_size());
	return (buffer);
}
