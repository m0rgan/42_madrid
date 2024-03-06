/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:17:53 by migumore          #+#    #+#             */
/*   Updated: 2024/03/06 20:02:23 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int			mode;
	int			num_commands;
	char		*infl;
	char		*commands;
	char		*outfl;
	int			fd_infile;
	int			fd_outfile;
	char		*cmd1;
	char		*cmd2;
	int			pipefd[2];
	pid_t		pid1;
	pid_t		pid2;
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

char	*ft_find_path(char *envp[]);
char	*ft_get_cmd(char **path, char *cmd);
char	**ft_split_command(const char *command, t_pipex *data);
void	ft_free_args(t_pipex *data);
void	ft_free_path(t_pipex *data);
void	ft_no_envp(t_pipex *data);

void	parse_argvb(int argc, char *argv[], t_pipex *data);
void	infile(t_pipex *data);
void	outfile(t_pipex *data);
void	input_cmd(t_pipex *data, int i);
void	output_cmd(t_pipex *data, int i);
void	get_cmd_and_execute(t_pipex *data, int i, char *envp[]);
void	close_pipes(t_pipex *data);
void	wait_pids(t_pipex *data);

#endif