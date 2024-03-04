/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:51 by migumore          #+#    #+#             */
/*   Updated: 2024/03/03 15:17:43 by migumore         ###   ########.fr       */
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

typedef struct s_pipex
{
	int			mode;
	int			num_commands;
	char		*infile;
	char		*commands;
	char		*outfile;
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
void	check_file1(t_pipex *data);
char	*find_path(char *envp[]);
char	*get_cmd(char **path, char *cmd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t original_size, size_t new_size);
char	**split_command(const char *command, t_pipex *data);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s, size_t n);
size_t	ft_strnlen(const char *s, size_t maxlen);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif