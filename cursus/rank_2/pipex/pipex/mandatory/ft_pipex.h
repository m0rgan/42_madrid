/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:51 by migumore          #+#    #+#             */
/*   Updated: 2024/03/04 16:25:37 by migumore         ###   ########.fr       */
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
# include "../../utils/utils.h"

typedef struct s_pipex
{
	char		*file1;
	char		*cmd1;
	char		*cmd2;
	char		*file2;
	int			fd_file1;
	int			fd_file2;
	int			pipefd[2];
	pid_t		pid1;
	pid_t		pid2;
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

#endif