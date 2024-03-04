/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:18:33 by migumore          #+#    #+#             */
/*   Updated: 2024/03/04 16:19:48 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*ft_find_path(char *envp[]);
char	*ft_get_cmd(char **path, char *cmd);
char	**ft_split_command(const char *command, t_pipex *data);

#endif