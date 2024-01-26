/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:18:07 by migumore          #+#    #+#             */
/*   Updated: 2023/11/25 18:17:39 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_number(char *str, int neg, int *num)
{
	char	*temp;

	temp = "";
	*num = (*num * 10) + (*str - 48);
	temp = str;
	str++;
	if (!(*str >= '0' && *str <= '9') && (*temp >= '0' && *temp <= '9'))
	{
		if (neg % 2 == 0)
			return (*num);
		return (*num = -(*num));
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	num;

	neg = 0;
	num = 0;
	while (!((*str >= '0' && *str <= '9') && *str == '-') && *str)
	{
		while (*str == '-')
		{
			neg++;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			if (get_number(str, neg, &num) != 0)
				return (num);
			str++;
			if (num == 0 && !(*str >= '0' && *str <= '9'))
				return (0);
		}
		str++;
	}
	return (0);
}
