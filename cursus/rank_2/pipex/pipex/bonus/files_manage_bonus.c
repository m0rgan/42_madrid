/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manage_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:07:31 by migumore          #+#    #+#             */
/*   Updated: 2024/03/18 13:17:11 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void	here_doc(t_pipex *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, data->limiter, ft_strlen(data->limiter)) == 0)
			break ;
		write(data->fd_infile, line, ft_strlen(line));
		free(line);
	}
}

void	infile(t_pipex *data)
{
	if (data->mode == 2)
	{
		data->fd_infile = open(data->infl, O_RDONLY);
		if (data->fd_infile < 0)
		{
			ft_free_path(data);
			perror("open infile");
			exit(1);
		}
	}
	else
	{
		data->fd_infile = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->fd_infile < 0)
		{
			ft_free_path(data);
			unlink("here_doc");
			perror("open here_doc");
			exit(1);
		}
		here_doc(data);
	}
}

void	outfile(t_pipex *data)
{
	if (data->mode == 2)
	{
		data->fd_outfile = open(data->outfl, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->fd_outfile < 0)
		{
			ft_free_path(data);
			perror("open outfile");
			exit(1);
		}
	}
	else
	{
		data->fd_outfile = open(data->outfl, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (data->fd_outfile < 0)
		{
			ft_free_path(data);
			perror("open outfile");
			exit(1);
		}
	}
}
