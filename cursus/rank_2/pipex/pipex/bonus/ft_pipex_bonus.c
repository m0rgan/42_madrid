/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/03/03 16:24:55 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	do_pipe(t_pipex *data, int i)
{
	if (i < data->num_commands - 1)
	{
		if (pipe(data->pipefd) == -1)
		{
			perror("pipe");
			exit(-1);
		}
	}
}

void	do_fork(t_pipex *data, int i)
{
	data->pids[i] = fork();
	if (data->pids[i] == -1)
	{
		perror("fork");
		exit(-1);
	}
}

void	infile(t_pipex *data)
{
	if (data->mode == 2)
	{
		data->fd_infile = open(data->infile, O_RDONLY);
		if (data->fd_infile < 0)
		{
			perror("Error!\nFile 1 is not readable");
			exit(127);
		}
		dup2(data->fd_infile, STDIN_FILENO);
		close(data->fd_infile);
	}
	else
	{
		data->fd_infile = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->fd_infile < 0)
		{
			perror("Error!\nFile 1 is not writable");
			exit(127);
		}
		dup2(data->fd_infile, STDIN_FILENO);
		close(data->fd_infile);
	}
}

void	outfile(t_pipex *data)
{
	if (data->mode == 2)
	{
		data->fd_outfile = open(data->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->fd_outfile < 0)
		{
			perror("Error!\nFile 2 is not writable");
			exit(127);
		}
		dup2(data->fd_outfile, STDOUT_FILENO);
		close(data->fd_outfile);
	}
	else
	{
		data->fd_outfile = open(data->outfile, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (data->fd_outfile < 0)
		{
			perror("Error!\nFile 2 is not writable");
			exit(127);
		}
		dup2(data->fd_outfile, STDOUT_FILENO);
		close(data->fd_outfile);
	}
}

void	input_cmd(t_pipex *data, int i)
{
	dup2(data->pipefd[2 * (i - 1)], STDIN_FILENO);
	close(data->pipefd[2 * (i - 1)]);
}

void	output_cmd(t_pipex *data, int i)
{
	dup2(data->pipefd[2 * i + 1], STDOUT_FILENO);
	close(data->pipefd[2 * i + 1]);
}

void	pipex(t_pipex *data, char *envp[])
{
	int		i;

	i = 0;
	data->pids = (char *)malloc(sizeof(pid_t) * data->num_commands);
	if (data->pids == NULL)
	{
		perror("Error!\nMemory allocation failed");
		exit(1);
	}
	while (i < data->num_commands)
	{
		do_pipe(data, i);
		do_fork(data, i);
		if (data->pids[i] == 0)
		{
			if (i == 0)
				infile(data);
			else
				input_cmd(data, i);
			if (i == data->num_commands - 1)
				outfile(data);
			else
				output_cmd(data, i);
			data->args = split_command(data->commands[i], data);
			data->cmd = get_cmd(data->path, data->args[0]);
			execve(data->cmd, data->args, envp);
			perror("execve");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data->num_commands - 1)
	{
		close(data->pipefd[2 * i]);
		close(data->pipefd[2 * i + 1]);
		i++;
	}
	i = 0;
	while (i < data->num_commands)
	{
		waitpid(data->pids[i], NULL, 0);
		i++;
	}
	free(data->pids);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;
	int		i;

	parse_argv(argc, argv, &data);
	data.path_envp = find_path(envp);
	data.path = ft_split(data.path_envp, ':');
	pipex(&data, envp);
	i = 0;
	while (data.path[i])
		free(data.path[i++]);
	free(data.path);
	return (WEXITSTATUS(data.status));
}
