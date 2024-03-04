/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:10:33 by migumore          #+#    #+#             */
/*   Updated: 2024/03/04 12:47:40 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

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

void	get_cmd_and_execute(t_pipex *data, int i, char *envp[])
{
	data->args = split_command(data->commands[i], data);
	data->cmd = get_cmd(data->path, data->args[0]);
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
		close(data->pipefd[2 * i]);
		close(data->pipefd[2 * i + 1]);
		i++;
	}
}

void	wait_pids(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->num_commands)
	{
		if (i == data->num_commands - 1)
			waitpid(data->pids[i], data->status, 0);
		else
			waitpid(data->pids[i], NULL, 0);
		i++;
	}
}
