/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:51:41 by migumore          #+#    #+#             */
/*   Updated: 2023/11/21 09:24:30 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char			dest[40];
	char			*src;
	unsigned int	size;

	src = "Wo2rld!";
	size = ft_strlcpy(dest, src, 10);
	printf("%d\n", size);
}

 #include <stdio.h>
 81
 82 int    main(void)
 83 {
 84     char    *s1;
 85     char    *s2;
 86
 87     s1 = "patata";
 88     s2 = "hola";
 89     printf("%s\n", s2);
 90     printf("%s\n", s1);
 91     return (0);
 92 }

 #include <stdio.h>
 81
 82 int    main(void)
 83 {
 84     char    *s1;
 85     char    *s2;
 86
 87     s1 = "patata";
 88     s2 = "hola";
 89     printf("%s\n", s2);
 90     printf("%s\n", s1);
 91     return (0);
 92 }