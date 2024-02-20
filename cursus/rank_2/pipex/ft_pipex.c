/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:30 by migumore          #+#    #+#             */
/*   Updated: 2024/02/20 16:13:11 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	char	*file1;
	char	*cmd1;
	char	*cmd2;
	char	*file2;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	file1 = argv[1];
	cmd1 = argv[2];
	cmd2 = argv[3];
	file2 = argv[4];
	if (argc != 5)
	{
		fprintf(stderr, "Usage: %s file1 cmd1 cmd2 file2\n", argv[0]);
		return (0);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		char *args1[] = {cmd1, NULL};
		execve(cmd1, args1, NULL);
		perror("execve");
		return (1);
	}
	else
	{
		pid2 = fork();
		if (pid2 == -1)
		{
			perror("fork");
			return (1);
		}
		if (pid2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			int fd = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
			{
				perror("open");
				return (1);
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
			char *args2[] = {cmd2, NULL};
			execve(cmd2, args2, NULL);
			perror("execve");
			return (1);
		}
		else
		{
			close(pipefd[0]);
			close(pipefd[1]);

			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
	return (0);
}
