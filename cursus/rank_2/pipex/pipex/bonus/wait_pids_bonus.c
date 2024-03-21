/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:03:26 by migumore          #+#    #+#             */
/*   Updated: 2024/03/21 17:03:47 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	wait_pids(t_pipex *data, int i)
{
	if (i == data->num_commands - 1)
		waitpid(data->pids[i], &data->status, 0);
	else
		waitpid(data->pids[i], NULL, 0);
}
