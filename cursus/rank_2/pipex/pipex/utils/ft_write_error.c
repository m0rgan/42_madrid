/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:27 by migumore          #+#    #+#             */
/*   Updated: 2024/03/25 15:01:44 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	write_error(char *msg, char *arg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putendl_fd(arg, STDERR_FILENO);
}
