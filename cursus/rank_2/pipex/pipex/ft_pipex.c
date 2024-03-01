/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/02/29 18:40:36 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	pid2_process(t_pipex *data, char *envp[])
{
	data->fd_file2 = open(data->file2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_file2 < 0)
	{
		perror("Error!\nFile 2 is not writable");
		exit(1);
	}
	dup2(data->fd_file2, STDOUT_FILENO);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[1]);
	close(data->fd_file2);
	data->args = ft_split(data->cmd2, ' ');
	data->cmd = get_cmd(data->path, data->args[0]);
	execve(data->cmd, data->args, envp);
	perror("execve cmd2");
	exit(1);
}

void	pid1_process(t_pipex *data, char *envp[])
{
	data->fd_file1 = open(data->file1, O_RDONLY);
	if (data->fd_file1 < 0)
	{
		perror("Error!\nFile 1 is not readable");
		exit(1);
	}
	dup2(data->fd_file1, STDIN_FILENO);
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
	close(data->fd_file1);
	data->args = ft_split(data->cmd1, ' ');
	data->cmd = get_cmd(data->path, data->args[0]);
	execve(data->cmd, data->args, envp);
	perror("execve cmd1");
	exit(1);
}

void	pipex(t_pipex *data, char *envp[])
{
	if (pipe(data->pipefd) == -1)
	{
		perror("pipe");
		exit(-1);
	}
	data->pid1 = fork();
	if (data->pid1 == -1)
	{
		perror("fork pid1");
		exit(-1);
	}
	if (data->pid1 == 0)
		pid1_process(data, envp);
	data->pid2 = fork();
	if (data->pid2 == -1)
	{
		perror("fork pid2");
		exit(-1);
	}
	if (data->pid2 == 0)
		pid2_process(data, envp);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, &data->status, 0);
}

void	c_leaks(void)
{
	system("leaks pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;
	int		i;

	i = 0;
	atexit(c_leaks);
	parse_argv(argc, argv, &data);
	check_file1(&data);
	data.path_envp = find_path(envp);
	data.path = ft_split(data.path_envp, ':');
	pipex(&data, envp);
	while (data.path[i])
		free(data.path[i++]);
	free(data.path);
	exit(data.status);
	return (0);
}
