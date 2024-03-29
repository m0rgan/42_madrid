/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:47:13 by migumore          #+#    #+#             */
/*   Updated: 2024/03/06 11:46:57 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void	process_quotes(t_pipex *data)
{
	data->quote = *data->pos++;
	data->start = data->pos;
	while (*data->pos && *data->pos != data->quote)
		data->pos++;
}

static int	process(t_pipex *data)
{
	data->start = data->pos;
	if (*data->pos == '"' || *data->pos == '\'')
		process_quotes(data);
	else
	{
		while (*data->pos && *data->pos != ' ')
			data->pos++;
	}
	if (data->size >= data->cap - 1)
	{
		data->cap *= 2;
		data->args = (char **)ft_realloc(data->args, data->size, data->cap);
		if (!data->args)
			return (1);
	}
	data->args[data->size] = ft_strndup(data->start, data->pos - data->start);
	if (!data->args[data->size])
		return (1);
	data->size++;
	if (*data->pos)
		data->pos++;
	return (0);
}

char	**ft_split_command(const char *command, t_pipex *data)
{
	data->cap = 10;
	data->size = 0;
	data->args = (char **)malloc(data->cap * sizeof(char *));
	if (!data->args)
		return (NULL);
	data->pos = command;
	while (1)
	{
		while (*data->pos && *data->pos == ' ')
			data->pos++;
		if (*data->pos == '\0')
			break ;
		if (process(data) == 1)
			return (NULL);
	}
	data->args[data->size] = NULL;
	return (data->args);
}
