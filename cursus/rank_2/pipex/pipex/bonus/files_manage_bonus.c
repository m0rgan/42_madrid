/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manage_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:07:31 by migumore          #+#    #+#             */
/*   Updated: 2024/03/11 17:22:35 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	here_doc(t_pipex *data)
{
	pid_t	pid;
	int		pipefd[2];
	char	*line;

	if (pipe(pipefd) == -1)
		pipe_error();
	pid = fork();
	if (pid == -1)
		fork_error();
	if (pid == 0)
	{
		close(pipefd[0]);
		while (1)
		{
			line = get_next_line(STDIN_FILENO);
			if (ft_strncmp(line, data->limiter, ft_strlen(data->limiter)) == 0)
			{
				free(line);
				break ;
			}
			write(pipefd[1], line, ft_strlen(line));
			write(pipefd[1], "\n", 1);
			free(line);
		}
		close(pipefd[1]);
		exit(0);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, &data->status, 0);
	}
}

void	infile(t_pipex *data)
{
	if (data->mode == 2)
	{
		printf("aqui");
		data->fd_infile = open(data->infl, O_RDONLY);
		if (data->fd_infile < 0)
		{
			ft_free_path(data);
			perror("open infile");
			exit(1);
		}
		dup2(data->fd_infile, STDIN_FILENO);
	}
	else
	{
		data->fd_infile = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->fd_infile < 0)
		{
			ft_free_path(data);
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
