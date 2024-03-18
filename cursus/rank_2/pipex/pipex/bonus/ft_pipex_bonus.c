/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/03/18 21:29:42 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void	pipe_error(t_pipex *data)
{
	ft_free_path(data);
	perror("pipe");
	exit(-1);
}

static void	fork_error(t_pipex *data)
{
	ft_free_path(data);
	perror("fork");
	exit(-1);
}

// static void	pipex(t_pipex *data, char *envp[], int i)
// {
// 	pid_t	pid;
// 	int		pipefd[2];

// 	if (i < data->num_commands - 1)
// 	{
// 		if (pipe(pipefd) == -1)
// 			pipe_error(data);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 		fork_error(data);
// 	if (pid == 0)
// 	{
// 		if (i == 0)
// 			dup_infile_n_close(data, &pipefd);
// 		else if (i == data->num_commands - 1)
// 			dup_outfile_n_close(data, &pipefd);
// 		else
// 			dup_cmds_n_close(&pipefd);
// 		get_cmd_and_execute(data, i, envp);
// 	}
// 	else
// 	{
// 		wait_pids(data, &pid, i);
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		wait_pids(data, &pid, i);
// 	}
// }

static void	pipex(t_pipex *data, char *envp[], int i)
{
	pid_t		pid;
	int			pipefd[2];
	static int	prev_pipefd[2] = {-1, -1};

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
		if (i == 0)
			dup_infile_n_close(data, &pipefd);
		else if (i != 0)
			dup2(prev_pipefd[0], STDIN_FILENO);
		if (i == data->num_commands - 1)
			dup_outfile_n_close(data, &pipefd);
		else if (i != data->num_commands - 1)
			dup2(pipefd[1], STDOUT_FILENO);
		if (i != 0)
		{
			close(prev_pipefd[0]);
			close(prev_pipefd[1]);
		}
		if (i != data->num_commands - 1)
		{
			close(pipefd[0]);
			close(pipefd[1]);
		}
		get_cmd_and_execute(data, i, envp);
		exit(0);
	}
	else
	{
		if (i != 0)
		{
			close(prev_pipefd[0]);
			close(prev_pipefd[1]);
		}
		if (i != data->num_commands - 1)
		{
			prev_pipefd[0] = pipefd[0];
			prev_pipefd[1] = pipefd[1];
		}
		wait_pids(data, &pid, i);
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
	i = 0;
	while (i < data.num_commands)
	{
		pipex(&data, envp, i);
		i++;
	}
	ft_free_path(&data);
	unlink("here_doc");
	return (WEXITSTATUS(data.status));
}
