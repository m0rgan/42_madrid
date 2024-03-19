/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/03/19 17:19:33 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void	do_pipe(t_pipex *data, int pipefd[2], int i)
{
	if (i < data->num_commands - 1)
	{
		if (pipe(pipefd) == -1)
		{
			ft_free_cmds_n_limiter(data);
			ft_free_path(data);
			perror("pipe");
			exit(-1);
		}
	}
}

static void	do_fork(pid_t *pid, t_pipex *data)
{
	*pid = fork();
	if (*pid == -1)
	{
		ft_free_cmds_n_limiter(data);
		ft_free_path(data);
		perror("fork");
		exit(-1);
	}
}

static void	wait_pids(t_pipex *data, pid_t *pid, int i)
{
	if (i == data->num_commands - 1)
		waitpid(*pid, &data->status, 0);
	else
		waitpid(*pid, NULL, 0);
}

static void	pipex(t_pipex *data, char *envp[], int i)
{
	pid_t		pid;
	int			pipefd[2];
	static int	prev_pipefd[2] = {-1, -1};

	do_pipe(data, pipefd, i);
	do_fork(&pid, data);
	if (pid == 0)
	{
		if (i == 0)
			dup_infile_n_close(data, &pipefd);
		else if (i == data->num_commands - 1)
			dup_outfile_n_close(data, &pipefd);
		else
			dup_cmds_n_close(&prev_pipefd, &pipefd);
		get_cmd_and_execute(data, i, envp);
	}
	else
	{
		close_pipes(data, &prev_pipefd, &pipefd, i);
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
	ft_free_cmds_n_limiter(&data);
	ft_free_path(&data);
	unlink("here_doc");
	return (WEXITSTATUS(data.status));
}
