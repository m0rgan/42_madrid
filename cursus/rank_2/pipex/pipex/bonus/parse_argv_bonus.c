/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:53:48 by migumore          #+#    #+#             */
/*   Updated: 2024/03/19 17:05:56 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	store_commands(t_pipex *data, char *argv[])
{
	int	i;

	data->commands = (char **)malloc(sizeof(char *) * (data->num_commands + 1));
	data->commands[data->num_commands] = NULL;
	if (data->commands == NULL)
	{
		free(data->limiter);
		perror("Error!\nMemory allocation failed");
		exit(1);
	}
	i = 0;
	while (i < data->num_commands)
	{
		if (data->mode == 2)
			data->commands[i] = ft_strdup(argv[i + data->mode]);
		else
			data->commands[i] = ft_strdup(argv[i + data->mode]);
		i++;
	}
}

void	parse_argvb(int argc, char *argv[], t_pipex *data)
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
			exit(1);
		}
		data->mode = 3;
		data->limiter = ft_strjoin(argv[2], "\n");
		data->outfl = argv[argc - 1];
		data->num_commands = argc - 4;
	}
	else
	{
		data->mode = 2;
		data->infl = argv[1];
		data->outfl = argv[argc - 1];
		data->num_commands = argc - 3;
	}
}
