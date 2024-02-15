/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:52:00 by migumore          #+#    #+#             */
/*   Updated: 2024/02/14 16:52:21 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	char	*str;
	char	*str2;

	str = ft_calloc(SIZE_MAX, SIZE_MAX);
	str2 = calloc(SIZE_MAX, SIZE_MAX);
	printf("%p\n", str);
	printf("%p\n", str2);
	return (0);
}
