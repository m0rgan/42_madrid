/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:50:59 by migumore          #+#    #+#             */
/*   Updated: 2024/02/05 18:54:03 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "unistd.h"
# include "limits.h"
# include "stdlib.h"
# include "stdio.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *src, unsigned int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*get_next_line(int fd);
char	*read_main(char *buffer, int fd);
char	*cut_line(char	*buffer);
char	*take_rest(char *buffer);

#endif