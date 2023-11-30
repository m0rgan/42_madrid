/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:17:00 by dgargant          #+#    #+#             */
/*   Updated: 2023/11/27 17:15:16 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int		ft_atoi(char *str);
char	*ft_strcpy(char *dest, char *src);

struct s_dictionary
{
	int		num;
	char	word[50];
} dict;

char	*ft_dictionary(char *buf)
{
	int		fd;
	ssize_t	nr_bytes;
	int		i;

	fd = open("numbers.dict", O_RDONLY);
	if (fd != -1)
	{
		nr_bytes = read(fd, buf, 700);
		close(fd);
		if (nr_bytes == 0)
			write(1, "Dict Error\n", 13);
		else
			return (buf);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_num_letters(char *buf, int p)
{
	struct s_dictionary	dic[40];
	int					i;


	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] >= '0' && buf[i] <= '9')
			dic[i].num = ft_atoi(buf);
		if (buf[i] >= 'a' && buf[i] <= 'z')
			ft_strcpy(dic[i].word, buf);
		i++;
	}
}
