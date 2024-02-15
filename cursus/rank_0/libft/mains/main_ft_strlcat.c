/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:57:16 by migumore          #+#    #+#             */
/*   Updated: 2024/01/25 17:22:00 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
    // Ejemplo de uso con ft_strlcat
    char dest1[20] = "sfdf";
    char *src1 = "pepe";
    size_t size1 = 8;
    size_t result1 = ft_strlcat(dest1, src1, size1);
    printf("Resultado de ft_strlcat: %s, Longitud total: %lu\n", dest1, result1);
    // Ejemplo de uso con strlcat
    char dest2[20] = "asff";
	char *src2 = "pepe";
    size_t size2 = 8;
    size_t result2 = strlcat(dest2, src2, size2);
    printf("Resultado de strlcat: %s, Longitud total: %zu\n", dest2, result2);
    return (0);
}
