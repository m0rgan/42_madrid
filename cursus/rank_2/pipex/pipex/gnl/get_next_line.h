/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:02:43 by migumore          #+#    #+#             */
/*   Updated: 2024/03/07 11:29:57 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../includes/includes.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*initialize_read_text(char *read_text);
char	*get_next_line(int fd);

#endif
