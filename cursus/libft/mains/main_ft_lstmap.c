/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:24:28 by migumore          #+#    #+#             */
/*   Updated: 2024/01/29 13:02:41 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*(*f)(void *list)
{
	((t_list *)list)->content += 5;
	return (list);
}

void	(*del)(void *list)
{
	free(list);
}

int	main(void)
{
	t_list	*list;
	t_list	*new_list;
	t_list	*temp;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = 1;
	new_list = ft_lstmap(list, f, del);
	printf("%i", new_list->content);
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	while (new_list != NULL)
	{
		temp = new_list;
		new_list = new_list->next;
		free(temp);
	}
	list = NULL;
	new_list = NULL;
	return (0);
}
