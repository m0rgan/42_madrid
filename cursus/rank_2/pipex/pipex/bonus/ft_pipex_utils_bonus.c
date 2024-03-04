/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:53:48 by migumore          #+#    #+#             */
/*   Updated: 2024/03/03 15:39:43 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	num_commands(t_pipex *data, char *argv[])
{
	int		i;

	data->commands = (char *)malloc(sizeof(char) * data->num_commands);
	if (data->commands == NULL)
	{
		perror("Error!\nMemory allocation failed");
		exit(1);
	}
	i = 0;
	while (i < data->num_commands)
	{
		if (data->mode == 2)
			data->commands[i] = argv[i + 2];
		else
			data->commands[i] = argv[i + 3];
		i++;
	}
}

void	parse_argv(int argc, char *argv[], t_pipex *data)
{
	if (argc < 5)
	{
		perror("Usage is: ./exec infile cmd1 cmd2 cmd3 ... cmdn outfile");
		perror("Usage is: ./exec here_doc LIMITATOR cmd cmd1 outfile");
		exit(127);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
		{
			perror("Usage is: ./exec here_doc LIMITATOR cmd cmd1 outfile");
			exit(127);
		}
		data->mode = 3;
		data->outfile = argv[argc - 1];
		data->num_commands = argc - 4;
	}
	else
	{
		data->mode = 2;
		data->infile = argv[1];
		data->outfile = argv[argc - 1];
		data->num_commands = argc - 3;
	}
	num_commands(data, argv);
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
