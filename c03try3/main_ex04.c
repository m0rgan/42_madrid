/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex04.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:55:15 by migumore          #+#    #+#             */
/*   Updated: 2023/11/27 15:21:01 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);
// Your function declarations
// int find_word(char *str, char *to_find, int *i);
// char *ft_strstr(char *str, char *to_find);

int main() {
    char haystack[] = "Hello, this is a strittest";
    char needle[] = "this";

    // Using original strstr function
    char *resultOriginal = strstr(haystack, needle);
    printf("Original strstr: %s\n", resultOriginal ? resultOriginal : "Not found");

    // Using your ft_strstr function
    int index = 0;
    char *resultCustom = ft_strstr(haystack, needle);
    printf("Custom ft_strstr: %s\n", resultCustom ? resultCustom : "Not found");

    // Compare results
    if ((resultOriginal == NULL && resultCustom == NULL) || (strcmp(resultOriginal, resultCustom) == 0)) {
        printf("Results match!\n");
    } else {
        printf("Results don't match!\n");
    }

    return 0;
}
