/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:51 by migumore          #+#    #+#             */
/*   Updated: 2024/02/27 14:39:45 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <cstring.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	*file1;
	char	*cmd1;
	char	*cmd2;
	char	*file2;
	pid_t	pid;
	int		temp_fd;
	int		status;
}	t_pipex;

#endif