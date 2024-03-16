/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/03/16 13:44:44 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void	parse_argv(int argc, char *argv[], t_pipex *data)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" infile cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
	data->infl = argv[1];
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->outfl = argv[4];
}

static void	pid2_process(t_pipex *data, char *envp[])
{
	data->fd_outfile = open(data->outfl, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_outfile < 0)
	{
		ft_free_path(data);
		perror("open outfile");
		exit(1);
	}
	dup2(data->fd_outfile, STDOUT_FILENO);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[1]);
	close(data->fd_outfile);
	data->args = ft_split_command(data->cmd2, data);
	data->cmd = ft_get_cmd(data->path, data->args[0]);
	if (!data->cmd)
	{
		ft_free_args(data);
		ft_free_path(data);
		perror("cmd2");
		exit(127);
	}
	execve(data->cmd, data->args, envp);
	perror("execve cmd2");
	exit(1);
}

static void	pid1_process(t_pipex *data, char *envp[])
{
	data->fd_infile = open(data->infl, O_RDONLY);
	if (data->fd_infile < 0)
	{
		ft_free_path(data);
		perror("open infile");
		exit(1);
	}
	dup2(data->fd_infile, STDIN_FILENO);
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
	close(data->fd_infile);
	data->args = ft_split_command(data->cmd1, data);
	data->cmd = ft_get_cmd(data->path, data->args[0]);
	if (!data->cmd)
	{
		ft_free_args(data);
		ft_free_path(data);
		perror("cmd1");
		exit(127);
	}
	execve(data->cmd, data->args, envp);
	perror("execve cmd1");
	exit(1);
}

static int	pipex(t_pipex *data, char *envp[])
{
	if (pipe(data->pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	data->pid1 = fork();
	if (data->pid1 == -1)
	{
		perror("fork pid1");
		return (-1);
	}
	if (data->pid1 == 0)
		pid1_process(data, envp);
	data->pid2 = fork();
	if (data->pid2 == -1)
	{
		perror("fork pid2");
		return (-1);
	}
	if (data->pid2 == 0)
		pid2_process(data, envp);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	waitpid(data->pid1, NULL, 0);
	return (waitpid(data->pid2, &data->status, 0));
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;

	parse_argv(argc, argv, &data);
	data.path_envp = ft_find_path(envp);
	data.path = ft_split(data.path_envp, ':');
	if (pipex(&data, envp) == -1)
	{
		ft_free_path(&data);
		return (1);
	}
	ft_free_path(&data);
	return (WEXITSTATUS(data.status));
}
