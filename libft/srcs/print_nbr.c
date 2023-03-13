/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:17:40 by gylim             #+#    #+#             */
/*   Updated: 2023/03/01 15:50:45 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_nbr(int fd, int nbr)
{
	int			idx;
	long long	temp_num;
	char		number[DEC_INT_MAX + 1];

	idx = DEC_INT_MAX;
	temp_num = nbr;
	if (temp_num < 0)
		temp_num = -temp_num;
	while (TRUE)
	{
		number[idx--] = DECIMAL[temp_num % 10];
		temp_num /= 10;
		if (!temp_num)
			break ;
	}
	if (nbr < 0)
	{
		number[idx] = '-';
		return (ft_write(fd, number + idx, DEC_INT_MAX - idx + 1));
	}
	return (ft_write(fd, number + idx + 1, DEC_INT_MAX - idx));
}
