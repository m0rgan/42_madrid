/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:53:48 by migumore          #+#    #+#             */
/*   Updated: 2024/03/01 19:58:09 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	parse_argv(int argc, char *argv[], t_pipex *data)
{
	if (argc != 5)
	{
		perror("Usage is: ./executable file1 cmd1 cmd2 file2");
		exit(1);
	}
	data->file1 = argv[1];
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->file2 = argv[4];
}

void	check_file1(t_pipex *data)
{
	if (access(data->file1, F_OK) == -1)
	{
		perror("file1");
		exit(0);
	}
}

char	*find_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_cmd(char **path, char *cmd)
{
	int		i;
	char	*temp;
	char	*cmd_path;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, 0) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}
