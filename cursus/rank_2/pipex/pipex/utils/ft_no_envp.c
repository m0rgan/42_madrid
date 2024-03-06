/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:59:23 by migumore          #+#    #+#             */
/*   Updated: 2024/03/06 20:14:18 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	ft_no_envp(t_pipex *data)
{
	ft_putendl_fd("1", data->fd_outfile);
	close(data->fd_outfile);
	exit(0);
}
