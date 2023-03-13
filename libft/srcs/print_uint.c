/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:21:33 by gylim             #+#    #+#             */
/*   Updated: 2023/03/01 15:27:14 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_uint(int fd, unsigned int nbr)
{
	int		idx;
	char	number[DEC_INT_MAX];

	idx = DEC_INT_MAX - 1;
	while (TRUE)
	{
		number[idx--] = DECIMAL[nbr % 10];
		nbr /= 10;
		if (!nbr)
			break ;
	}
	return (ft_write(fd, number + idx + 1, DEC_INT_MAX - idx - 1));
}
