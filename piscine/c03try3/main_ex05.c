/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex05.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:33:00 by migumore          #+#    #+#             */
/*   Updated: 2023/11/27 15:26:32 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
    // Ejemplo de uso con ft_strlcat
    char dest1[20] = "Hello, ";
    char *src1 = "pepe";
    unsigned int size1 = 1;
    unsigned int result1 = ft_strlcat(dest1, src1, size1);
    printf("Resultado de ft_strlcat: %s, Longitud total: %u\n", dest1, result1);
    // Ejemplo de uso con strlcat
    char dest2[20] = "Hello, ";
	char *src2 = "pepe";
    size_t size2 = 1;
    size_t result2 = strlcat(dest2, src2, size2);
    printf("Resultado de strlcat: %s, Longitud total: %zu\n", dest2, result2);
    return 0;
}