/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:51 by migumore          #+#    #+#             */
/*   Updated: 2024/02/28 18:00:47 by migumore         ###   ########.fr       */
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
	char	*path_envp;
	int		fd_file1;
	int		fd_file2;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*args[2];
	int		status;
}	t_pipex;

void	pipex(t_pipex *data);
void	pid1_process(t_pipex *data);
void	pid2_process(t_pipex *data);
void	parse_argv(int argc, char *argv[], t_pipex *data);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	check_file1(t_pipex *data);
char	**split(char const *s, char c);

#endif