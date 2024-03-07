/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/03/07 18:33:25 by migumore         ###   ########.fr       */
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

// static void	do_pipe(t_pipex *data, int i)
// {
// 	if (i < data->num_commands - 1)
// 	{
// 		if (pipe(data->pipefd) == -1)
// 		{
// 			perror("pipe");
// 			exit(-1);
// 		}
// 	}
// }

// static void	do_fork(t_pipex *data)
// {
// 	pids = fork();
// 	if (pids == -1)
// 	{
// 		perror("fork");
// 		exit(-1);
// 	}
// }

static void	pipex(t_pipex *data, char *envp[], int i)
{
	pid_t		pid;

	// do_pipe(data, i);
	// do_fork(pids);
	if (pipe(data->pipefd) == -1)
	{
		perror("pipe");
		exit(-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(-1);
	}
	printf("i: %d\n", i);
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
	// close_pipes(data);
	close(data->pipefd[1]);
	dup2(data->pipefd[0], STDIN_FILENO);
	// wait_pids(data);
	waitpid(pid, &data->status, 0);
	// free(data->pids);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;
	int		i;

	parse_argvb(argc, argv, &data);
	data.path_envp = ft_find_path(envp);
	data.path = ft_split(data.path_envp, ':');
	//allocate_pids(&data);
	i = 0;
	while (i < data.num_commands)
	{
		pipex(&data, envp, i);
		i++;
	}
	ft_free_args(&data);
	return (WEXITSTATUS(data.status));
}
