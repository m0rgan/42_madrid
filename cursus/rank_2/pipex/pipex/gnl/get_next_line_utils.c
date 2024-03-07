/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:54:01 by migumore          #+#    #+#             */
/*   Updated: 2024/03/07 11:30:52 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*initialize_read_text(char *read_text)
{
	if (!read_text)
	{
		read_text = (char *)malloc(sizeof(char));
		if (!read_text)
			return (NULL);
		read_text[0] = '\0';
	}
	return (read_text);
}
