/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumore <migumore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:07:30 by migumore          #+#    #+#             */
/*   Updated: 2023/11/24 12:51:11 by migumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_base_parameters(char *base, char params[2])
{
	int		count1;
	int		count2;

	count1 = 0;
	count2 = count1 + 1;
	params[0] = 0;
	params[1] = 0;
	while (base[count1])
	{
		count2 = count1 + 1;
		while (base[count2])
		{
			if (base[count1] == base[count2]
				|| base[count2] == '+'
				|| base[count2] == '-'
				|| base[count2] == ' ')
				params[0] = 1;
			count2++;
		}
		count1++;
	}
	params[1] = count1;
}

// void	ft_putnbr(long nb, int length, char *base)
// {
// 	char	result[11];
// 	int		neg;
// 	int		i;

// 	neg = 1;
// 	i = 0;
// 	if (nb < 0)
// 	{
// 		neg = -1;
// 		nb = -nb;
// 	}
// 	if (nb >= length)
// 	{
// 		ft_putnbr(nb / length, length, base);
// 	}
// 	result[i] = base[nb % length];
// 	write(1, &d, 1);
// }

// int	get_number(char *str, int neg, int *num)
// {
// 	char	*temp;

// 	temp = "";
// 	*num = (*num * 10) + (*str - 48);
// 	temp = str;
// 	str++;
// 	if (!(*str >= '0' && *str <= '9') && (*temp >= '0' && *temp <= '9'))
// 	{
// 		if (neg % 2 == 0)
// 			return (*num);
// 		return (*num = -(*num));
// 	}
// 	return (0);
// }

int	ft_atoi(char *str, int length, char *base)
{
	int		neg;
	int		num;
	int		dig_ok;
	char	*str_ini;
	char	*base_ini;

	neg = 0;
	num = 0;
	dig_ok = 0;
	str_ini = str;
	base_ini = base;
	while (*str)
	{
		base = base_ini;
		while (*base)
		{
			if (*str == *base)
				dig_ok++;
			base++;
		}
		str++;
	}
	if (length != dig_ok)
		return (0);
	// str = str_ini;
	// while (*str >= '0' && *str <= '9')
	// {
	// 	if (get_number(str, neg, &num) != 0)
	// 		return (num);
	// 	str++;
	// 	if (num == 0 && !(*str >= '0' && *str <= '9'))
	// 		return (0);
	// }
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	char	params[2];
	int		num;
	int		length;

	ft_base_parameters(base, params);
	num = 0;
	length = params[1];
	if (params[0] == 0 && length > 1)
	{
		num = ft_atoi(str, length, base);
	}
	return (num);
}

int	main(void)
{
	return (ft_atoi_base("afd", "0123456789abcdef"));
}
