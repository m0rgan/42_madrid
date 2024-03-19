/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:50:18 by migumore          #+#    #+#             */
/*   Updated: 2024/03/19 17:16:30 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	ft_free_args(t_pipex *data)
{
	int	i;

	i = 0;
	while (data->args[i])
	{
		free(data->args[i]);
		i++;
	}
	free(data->args);
	free(data->cmd);
}

void	ft_free_path(t_pipex *data)
{
	int	i;

	i = 0;
	while (data->path[i])
		free(data->path[i++]);
	free(data->path);
}

void	ft_free_cmds_n_limiter(t_pipex *data)
{
	free(data->limiter);
	free(data->commands);
}
