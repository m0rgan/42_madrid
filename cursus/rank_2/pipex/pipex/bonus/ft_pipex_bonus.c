/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/03/06 11:21:23 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	allocate_pids(t_pipex *data)
{
	data->pids = malloc(sizeof(pid_t) * data->num_commands);
	if (data->pids == NULL)
	{
		perror("Error!\nMemory allocation failed");
		exit(1);
	}
}

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

void	pipex(t_pipex *data, char *envp[])
{
	int		i;

	i = 0;
	allocate_pids(data);
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
			get_cmd_and_execute(data, i, envp);
		}
		i++;
	}
	close_pipes(data);
	wait_pids(data);
	free(data->pids);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;
	int		i;

	parse_argvb(argc, argv, &data);
	data.path_envp = ft_find_path(envp);
	data.path = ft_split(data.path_envp, ':');
	pipex(&data, envp);
	i = 0;
	while (data.path[i])
		free(data.path[i++]);
	free(data.path);
	return (WEXITSTATUS(data.status));
}
