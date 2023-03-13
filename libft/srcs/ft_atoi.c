/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:43:19 by gylim             #+#    #+#             */
/*   Updated: 2022/12/19 17:41:51 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num(int sign, const char *str)
{
	long long	prev;
	long long	res;

	res = 0;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		prev = res;
		res = res * 10 + *str - '0';
		if (prev != res / 10)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		str++;
	}
	return ((int)(sign * res));
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (get_num(sign, str));
}
