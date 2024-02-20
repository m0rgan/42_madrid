/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/02/20 17:00:06 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	parse_args(int argc, char *argv[], t_pipex *data)
{
	if (argc != 5)
	{
		fprintf(stderr, "Usage: %s file1 cmd1 cmd2 file2\n", argv[0]);
		exit(0);
	}
	data->file1 = argv[1];
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->file2 = argv[4];
}

void	setup_and_fork_first_child(t_pipex *data)
{
	char	*args1[2];

	if (pipe(data->pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	data->pid1 = fork();
	if (data->pid1 == -1)
	{
		perror("fork");
		exit(1);
	}
	if (data->pid1 == 0)
	{
		close(data->pipefd[0]);
		dup2(data->pipefd[1], STDOUT_FILENO);
		close(data->pipefd[1]);
		args1[0] = data->cmd2;
		args1[1] = NULL;
		execve(data->cmd1, args1, NULL);
		perror("execve");
		exit(1);
	}
}

void	setup_and_fork_second_child(t_pipex *data)
{
	char	*args2[2];

	data->pid2 = fork();
	if (data->pid2 == -1)
	{
		perror("fork");
		exit(1);
	}
	if (data->pid2 == 0)
	{
		close(data->pipefd[1]);
		dup2(data->pipefd[0], STDIN_FILENO);
		close(data->pipefd[0]);
		data->fd = open(data->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->fd == -1)
		{
			perror("open");
			exit(1);
		}
		dup2(data->fd, STDOUT_FILENO);
		close(data->fd);
		args2[0] = data->cmd2;
		args2[1] = NULL;
		execve(data->cmd2, args2, NULL);
		perror("execve");
		exit(1);
	}
	else
	{
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		waitpid(data->pid2, NULL, 0);
	}
}

int	main(int argc, char *argv[])
{
	t_pipex	data;

	parse_args(argc, argv, &data);
	setup_and_fork_first_child(&data);
	setup_and_fork_second_child(&data);
	waitpid(data.pid1, NULL, 0);
	return (0);
}
