/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/03/14 14:44:06 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	pipe_error(t_pipex *data)
{
	ft_free_path(data);
	perror("pipe");
	exit(-1);
}

void	fork_error(t_pipex *data)
{
	ft_free_path(data);
	perror("fork");
	exit(-1);
}

static void	pipex(t_pipex *data, char *envp[], int i)
{
	pid_t	pid;
	int		pipefd[2];

	if (i < data->num_commands - 1)
	{
		if (pipe(pipefd) == -1)
			pipe_error(data);
	}
	pid = fork();
	if (pid == -1)
		fork_error(data);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		get_cmd_and_execute(data, i, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, &data->status, 0);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;
	int		i;

	parse_argvb(argc, argv, &data);
	store_commands(&data, argv);
	data.path_envp = ft_find_path(envp);
	data.path = ft_split(data.path_envp, ':');
	infile(&data);
	outfile(&data);
	i = data.mode;
	while (i < data.num_commands)
	{
		pipex(&data, envp, i);
		i++;
	}
	dup2(data.fd_outfile, STDOUT_FILENO);
	get_cmd_and_execute(&data, i, envp);
	ft_free_path(&data);
	return (WEXITSTATUS(data.status));
}
