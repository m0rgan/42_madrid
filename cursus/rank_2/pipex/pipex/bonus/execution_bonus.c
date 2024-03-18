/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:10:33 by migumore          #+#    #+#             */
/*   Updated: 2024/03/18 21:26:28 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	dup_infile_n_close(t_pipex *data, int (*pipefd)[2])
{
	close((*pipefd)[0]);
	dup2(data->fd_infile, STDIN_FILENO);
	dup2((*pipefd)[1], STDOUT_FILENO);
	close(data->fd_infile);
}

void	dup_outfile_n_close(t_pipex *data, int (*pipefd)[2])
{
	dup2(data->fd_outfile, STDOUT_FILENO);
	dup2((*pipefd)[0], STDIN_FILENO);
	close((*pipefd)[1]);
	close(data->fd_outfile);
}

// void	dup_cmds_n_close(int (*prev_pipefd)[2], int (*next_pipefd)[2])
// {
// 	dup2((*prev_pipefd)[0], STDIN_FILENO);
// 	close((*prev_pipefd)[0]);
// 	close((*prev_pipefd)[1]);

// 	if (next_pipefd != NULL) {
// 		dup2((*next_pipefd)[1], STDOUT_FILENO);
// 		close((*next_pipefd)[0]);
// 		close((*next_pipefd)[1]);
// 	}
// }

// void	dup_cmds_n_close(int (*pipefd)[2])
// {
// 	dup2((*pipefd)[0], STDIN_FILENO);
// 	dup2((*pipefd)[1], STDOUT_FILENO);
// 	close((*pipefd)[0]);
// 	close((*pipefd)[1]);
// }



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
	printf("cmd %i: %s\n", i, data->cmd);
	execve(data->cmd, data->args, envp);
	perror("execve");
	exit(1);
}

void	wait_pids(t_pipex *data, pid_t *pid, int i)
{
	if (i == data->num_commands - 1)
		waitpid(*pid, &data->status, 0);
	else
		waitpid(*pid, NULL, 0);
}
