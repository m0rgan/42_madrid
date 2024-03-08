/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/03/08 18:01:14 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

// static void	allocate_pids(t_pipex *data)
// {
// 	data->pids = malloc(sizeof(pid_t) * data->num_commands);
// 	if (data->pids == NULL)
// 	{
// 		perror("Error!\nMemory allocation failed");
// 		exit(1);
// 	}
// }

static void	do_pipe(t_pipex *data, int i)
{
	if (i < data->num_commands - 1)
	{
		if (pipe(data->pipefd) == -1)
		{
			perror("pipe");
			exit(-1);
		}
	}
}

static void	do_fork(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit(-1);
	}
}

static void	pipex(t_pipex *data, char *envp[], int i)
{
	pid_t		pid;

	do_pipe(data, i);
	do_fork(&pid);
	if (pid == 0)
	{
		if (i == 0)
			infile(data);
		else
			input_cmd(data);
		if (i == data->num_commands - 1)
			outfile(data);
		else
			output_cmd(data);
		printf("i: %d\n", i);
		printf("Executing command: %s\n", data->commands[i]);
		get_cmd_and_execute(data, i, envp);
	}
	close_pipes(data);
	wait_pids(data, &pid);
	// free(data->pids);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;
	int		i;

	parse_argvb(argc, argv, &data);
	data.path_envp = ft_find_path(envp);
	data.path = ft_split(data.path_envp, ':');
	if (data.mode == 2)
	{
		infile(&data);
		outfile(&data);
	}
	i = 0;
	while (i < data.num_commands)
	{
		pipex(&data, envp, i);
		i++;
	}
	ft_free_args(&data);
	return (WEXITSTATUS(data.status));
}
