/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/02/26 18:17:50 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	parse_args(int argc, char *argv[], t_pipex *data)
{
	if (argc != 5)
	{
		perror("Error!\nUsage is: ./executable file1 cmd1 cmd2 file2\n");
		exit(1);
	}
	else
	{
		data->file1 = argv[1];
		data->cmd1 = argv[2];
		data->cmd2 = argv[3];
		data->file2 = argv[4];
	}
}

void	check_file1(t_pipex *data)
{
	if (access(data->file1, F_OK) == -1)
	{
		perror("Error!\nFile 1 does not exist\n");
		exit(1);
	}
	else if (access(data->file1, R_OK) == -1)
	{
		perror("Error!\nFile 1 is not readable\n");
		exit(1);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	execute_script(t_pipex *data)
{
	data->pid = fork();
	if (data->pid == -1)
	{
		unlink("temp.sh");
		perror("fork failed");
		exit(1);
	}
	if (data->pid == 0)
	{
		if (execve("temp.sh", NULL, NULL) == -1)
		{
			unlink("temp.sh");
			perror("execve failed");
			exit(1);
		}
	}
	else
	{
		waitpid(data->pid, &data->status, 0);
		unlink("temp.sh");
	}
}

void	script_file(t_pipex *data)
{
	data->temp_fd = open("temp.sh", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	write(data->temp_fd, "#!/bin/bash\n<", 13);
	write(data->temp_fd, data->file1, ft_strlen(data->file1));
	write(data->temp_fd, " ", 1);
	write(data->temp_fd, data->cmd1, ft_strlen(data->cmd1));
	write(data->temp_fd, " | ", 3);
	write(data->temp_fd, data->cmd2, ft_strlen(data->cmd2));
	write(data->temp_fd, " >", 2);
	write(data->temp_fd, data->file2, ft_strlen(data->file2));
	close(data->temp_fd);
	execute_script(data);
}

int	main(int argc, char *argv[])
{
	t_pipex	data;

	parse_args(argc, argv, &data);
	check_file1(&data);
	script_file(&data);
	return (0);
}
