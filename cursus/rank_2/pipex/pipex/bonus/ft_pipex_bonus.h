/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:51 by migumore          #+#    #+#             */
/*   Updated: 2024/03/04 16:25:49 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../../utils/utils.h"

typedef struct s_pipex
{
	int			mode;
	int			num_commands;
	char		*infl;
	char		*commands;
	char		*outfl;
	int			fd_infile;
	int			fd_outfile;
	int			pipefd[2];
	pid_t		*pids;
	char		*path_envp;
	char		**path;
	char		*cmd;
	int			status;
	int			cap;
	int			size;
	char		**args;
	const char	*pos;
	const char	*start;
	char		quote;
}	t_pipex;

void	parse_argv(int argc, char *argv[], t_pipex *data);
void	infile(t_pipex *data);
void	outfile(t_pipex *data);
void	input_cmd(t_pipex *data, int i);
void	output_cmd(t_pipex *data, int i);
void	get_cmd_and_execute(t_pipex *data, int i, char *envp[]);
void	close_pipes(t_pipex *data);
void	wait_pids(t_pipex *data);

#endif