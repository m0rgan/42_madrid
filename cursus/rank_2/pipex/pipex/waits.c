/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:55 by migumore          #+#    #+#             */
/*   Updated: 2024/02/27 17:37:36 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	parent1_waits(t_pipex *data)
{
	waitpid(data->pid1, &data->status, 0);
	if (WIFEXITED(data->status) && WEXITSTATUS(data->status) != 0)
	{
		perror("Child process exited with an error");
		exit(1);
	}
	close(data->pipefd[1]);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[0]);
	cmd_to_outfile(data);
}

void	parent2_waits(t_pipex *data)
{
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	waitpid(data->pid2, &data->status, 0);
	if (WIFEXITED(data->status) && WEXITSTATUS(data->status) != 0)
	{
		perror("Child process exited with an error");
		exit(1);
	}
	exit(0);
}
