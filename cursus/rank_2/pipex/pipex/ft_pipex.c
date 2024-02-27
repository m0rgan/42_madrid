/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/02/27 18:11:52 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	cmd_to_outfile(t_pipex *data)
{
	data->pid2 = fork();
	if (data->pid2 == -1)
	{
		perror("fork error\n");
		exit(1);
	}
	if (data->pid2 == 0)
	{
		dup2(data->fd_file2, STDOUT_FILENO);
		close(data->fd_file2);
		data->args[0] = data->file2;
		data->args[1] = NULL;
		execve(data->cmd2, data->args, NULL);
		perror("execve");
		exit(1);
	}
	else
		parent2_waits(data);
}

void	parent_process(t_pipex *data)
{
	waitpid(data->pid1, &data->status, 0);
	dup2(data->file2, STDOUT_FILENO);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[1]);
	close(data->file2);
	execve(data->cmd1, data->args, NULL);
	perror("execve error\n");
	exit(1);
}

void	child_process(t_pipex *data)
{
	dup2(data->file1, STDIN_FILENO);
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
	close(data->file1);
	execve(data->cmd1, data->args, NULL);
	perror("execve error\n");
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
		perror("fork error\n");
		exit(1);
	}
	if (data->pid1 == 0)
		child_process(data);
	else
		parent_process(data);
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

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	data;

	parse_argv(argc, argv, &data);
	check_file1(&data);
	data.fd_file1 = open(data.file1, O_RDONLY);
	data.fd_file2 = open(data.file2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data.fd_file1 < 0 || data.fd_file2 < 0)
		return (-1);
	pipex(&data, envp);
	return (0);
}
