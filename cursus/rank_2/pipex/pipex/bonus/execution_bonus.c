/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:10:33 by migumore          #+#    #+#             */
/*   Updated: 2024/03/11 16:24:12 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	input_cmd(t_pipex *data)
{
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[1]);
}

void	output_cmd(t_pipex *data)
{
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
}

void	get_cmd_and_execute(t_pipex *data, int i, char *envp[])
{
	data->args = ft_split_command(data->commands[i], data);
	data->cmd = ft_get_cmd(data->path, data->args[0]);
	if (!data->cmd)
	{
		ft_free_args(data);
		ft_free_path(data);
		perror("cmd");
		exit(127);
	}
	execve(data->cmd, data->args, envp);
	perror("execve");
	exit(1);
}

void	close_pipes(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->num_commands - 1)
	{
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		i++;
	}
}

void	wait_pids(t_pipex *data, pid_t *pid)
{
	int	i;

	i = 0;
	while (i < data->num_commands)
	{
		if (i == data->num_commands - 1)
			waitpid(*pid, &data->status, 0);
		else
			waitpid(*pid, NULL, 0);
		i++;
	}
}
