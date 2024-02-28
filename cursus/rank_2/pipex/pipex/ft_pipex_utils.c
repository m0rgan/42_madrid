/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:53:48 by migumore          #+#    #+#             */
/*   Updated: 2024/02/28 12:57:40 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start];
		i++;
		start++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

void	parse_argv(int argc, char *argv[], t_pipex *data)
{
	if (argc != 5)
	{
		perror("Error!\nUsage is: ./executable file1 cmd1 cmd2 file2\n");
		exit(1);
	}
	data->file1 = argv[1];
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->file2 = argv[4];
}

void	check_file1(t_pipex *data)
{
	if (access(data->file1, F_OK) == -1)
	{
		perror("Error!\nFile 1 does not exist\n");
		exit(1);
	}
}
