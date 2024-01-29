/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:24:28 by migumore          #+#    #+#             */
/*   Updated: 2024/01/29 12:33:03 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*(*f)(void *)
{
	*list->content += 5;
}

void	(*del)(void *)
{
	free(list);
}

int	main(void)
{
	t_list	*list;

	list->content = 1;
	printf("%i", ft_lstmap(list, f(), del()));
	return (0);
}
