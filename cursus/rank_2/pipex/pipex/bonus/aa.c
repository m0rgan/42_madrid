/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:37:20 by migumore          #+#    #+#             */
/*   Updated: 2024/03/11 16:37:23 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	incmd_process(t_pipex *data, char *envp[], int i)
{
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
	data->args = ft_split_command(data->commands[i], data);
	data->cmd = ft_get_cmd(data->path, data->args[0]);
	if (!data->cmd)
	{
		ft_free_args(data);
		ft_free_path(data);
		perror("cmd");
		exit(127);
	}
	execve(data->cmd, data->args, envp);
	perror("execve");
	exit(1);
}

static void	outfile_process(t_pipex *data, char *envp[], int i)
{
	dup2(data->fd_outfile, STDOUT_FILENO);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[1]);
	close(data->fd_outfile);
	data->args = ft_split_command(data->commands[i], data);
	data->cmd = ft_get_cmd(data->path, data->args[0]);
	if (!data->cmd)
	{
		ft_free_args(data);
		ft_free_path(data);
		perror("cmd");
		exit(127);
	}
	execve(data->cmd, data->args, envp);
	perror("execve");
	exit(1);
}

static void	infile_process(t_pipex *data, char *envp[], int i)
{
	dup2(data->fd_infile, STDIN_FILENO);
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
	close(data->fd_infile);
	data->args = ft_split_command(data->commands[i], data);
	data->cmd = ft_get_cmd(data->path, data->args[0]);
	if (!data->cmd)
	{
		ft_free_args(data);
		ft_free_path(data);
		perror("cmd");
		exit(127);
	}
	execve(data->cmd, data->args, envp);
	perror("execve");
	exit(1);
}