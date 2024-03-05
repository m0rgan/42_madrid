/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:53:48 by migumore          #+#    #+#             */
/*   Updated: 2024/03/05 15:51:09 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

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
			data->commands[i] = *argv[i + 2];
		else
			data->commands[i] = *argv[i + 3];
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
			exit(127);
		}
		data->mode = 3;
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
	num_commands(data, argv);
}
