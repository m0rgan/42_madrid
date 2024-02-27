/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:51 by migumore          #+#    #+#             */
/*   Updated: 2024/02/27 18:08:39 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	*file1;
	char	*cmd1;
	char	*cmd2;
	char	*file2;
	int		fd_file1;
	int		fd_file2;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*args[2];
	int		status;
}	t_pipex;

void	cmd_to_outfile(t_pipex *data);
void	infile_to_cmd(t_pipex *data);
void	check_file1(t_pipex *data);
void	parse_args(int argc, char *argv[], t_pipex *data);
void	parent1_waits(t_pipex *data);
void	parent2_waits(t_pipex *data);

#endif