/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manage_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:07:31 by migumore          #+#    #+#             */
/*   Updated: 2024/03/06 11:29:41 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	infile(t_pipex *data)
{
	if (data->mode == 2)
	{
		data->fd_infile = open(data->infl, O_RDONLY);
		if (data->fd_infile < 0)
		{
			perror("open infile");
			exit(1);
		}
		dup2(data->fd_infile, STDIN_FILENO);
		close(data->fd_infile);
	}
	else
	{
		data->fd_infile = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->fd_infile < 0)
		{
			perror("open here_doc");
			exit(1);
		}
		dup2(data->fd_infile, STDIN_FILENO);
		close(data->fd_infile);
	}
}

void	outfile(t_pipex *data)
{
	if (data->mode == 2)
	{
		data->fd_outfile = open(data->outfl, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->fd_outfile < 0)
		{
			perror("open outfile");
			exit(1);
		}
		dup2(data->fd_outfile, STDOUT_FILENO);
		close(data->fd_outfile);
	}
	else
	{
		data->fd_outfile = open(data->outfl, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (data->fd_outfile < 0)
		{
			perror("open outfile");
			exit(1);
		}
		dup2(data->fd_outfile, STDOUT_FILENO);
		close(data->fd_outfile);
	}
}
