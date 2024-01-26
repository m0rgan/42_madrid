/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:36:41 by migumore          #+#    #+#             */
/*   Updated: 2023/11/27 11:55:30 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_word(char *str, char *to_find, int *i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (to_find[j] != '\0')
	{
		if (str[*i] == to_find[k])
		{
			*i += 1;
			k++;
		}
		j++;
	}
	if (to_find[k] == '\0')
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			pos = i;
			if (find_word(str, to_find, &i) == 1)
				return (&str[pos]);
		}
		i++;
	}
	return (0);
}
