/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/02/28 18:00:42 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	pid2_process(t_pipex *data)
{
	data->fd_file2 = open(data->file2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_file2 < 0)
	{
		perror("Error!\nFile 2 is not writable\n");
		exit(1);
	}
	dup2(data->fd_file2, STDOUT_FILENO);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[1]);
	close(data->fd_file2);
	execve(data->cmd2, data->args, NULL);
	perror("execve error\n");
	exit(1);
}

void	pid1_process(t_pipex *data)
{
	data->fd_file1 = open(data->file1, O_RDONLY);
	if (data->fd_file1 < 0)
	{
		perror("Error!\nFile 1 is not readable\n");
		exit(1);
	}
	dup2(data->fd_file1, STDIN_FILENO);
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
	close(data->fd_file1);
	execve("/bin/ls", data->args, NULL);
	perror("execve error cmd1\n");
	exit(1);
}

void	pipex(t_pipex *data)
{
	if (pipe(data->pipefd) == -1)
	{
		perror("pipe error\n");
		exit(1);
	}
	data->pid1 = fork();
	if (data->pid1 == -1)
	{
		perror("fork error pid1\n");
		exit(1);
	}
	if (data->pid1 == 0)
		pid1_process(data);
	data->pid2 = fork();
	if (data->pid2 == -1)
	{
		perror("fork error pid2\n");
		exit(1);
	}
	if (data->pid2 == 0)
		pid2_process(data);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	waitpid(data->pid1, &data->status, 0);
	waitpid(data->pid2, &data->status, 0);
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	data;

	printf("%s\n", envp[0]);
	parse_argv(argc, argv, &data);
	check_file1(&data);
	pipex(&data);
	return (0);
}
