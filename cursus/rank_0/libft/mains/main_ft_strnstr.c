/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:05:53 by migumore          #+#    #+#             */
/*   Updated: 2024/01/22 20:16:03 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>

int main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	printf("%s", ft_strnstr(haystack, needle, -1));
	return (0);
}

// int	main(void)
// {
// 	char	*haystack;
// 	char	*needle;
// 	char	*og_match;
// 	char	*my_match;

// 	haystack = "foo bar bar baz";
// 	needle = "bar";
// 	char haystack[30] = "aaabcabcd";
//     char needle[10] = "aabc";
// 	og_match = strnstr(haystack, needle, 12);
// 	my_match = ft_strnstr(haystack, needle, 12);
// 	if (og_match)
// 		printf("%s\n", og_match);
// 	if (my_match)
// 		printf("%s\n", my_match);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*og_match;
// 	char	*my_match;

// 	char haystack[30] =  
// 	og_match = strnstr(haystack, needle, 12);
// 	my_match = ft_strnstr(haystack, needle, 12);
// 	if (og_match)
// 		printf("%s\n", og_match);
// 	if (my_match)
// 		printf("%s\n", my_match);
// 	return (0);
// }
