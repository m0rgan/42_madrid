/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:49:56 by migumore          #+#    #+#             */
/*   Updated: 2023/11/21 09:51:04 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

int		is_alpha(char *str, int *i);
char	*strupcase(char *str, int *i);
int		is_lowercase(char *str, int *i);
int		is_uppercase(char *str, int *i);
char	*strlowcase(char *str, int *i);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alpha(&str[i], &i) == 1)
		{
			if (is_uppercase(&str[i], &i) == 0)
			{
				if (is_alpha(&str[i + 1], &i) == 1)
				{
					str[i] = *strupcase(&str[i], &i);
					while (is_lowercase(&str[i + 1], &i) == 1)
					{
						i++;
					}
				}
			}
			else
			{
				if (is_uppercase(&str[i - 1], &i) == 1)
				{
					while (is_uppercase(&str[i], &i) == 1)
					{
						str[i] = *strlowcase(&str[i], &i);
						i++;
					}
				}
			}
		}
		i++;
	}
	return (str);
}

int	is_alpha(char *str, int *i)
{
	if ((str[*i] < 65 || str[*i] > 90) && (str[*i] < 97 || str[*i] > 122))
	{
		return (0);
	}
	return (1);
}

char	*strupcase(char *str, int *i)
{
	if (str[*i] >= 97 && str[*i] <= 122)
	{
		str[*i] = str[*i] - 32;
	}
	return (str);
}

int	is_lowercase(char *str, int *j)
{
	if (str[*j] < 97 || str[*j] > 122)
	{
		return (0);
	}
	return (1);
}

char	*strlowcase(char *str, int *i)
{
	if (str[*i] >= 65 && str[*i] <= 90)
	{
		str[*i] = str[*i] + 32;
	}
	return (str);
}
