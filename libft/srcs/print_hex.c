/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:20:21 by gylim             #+#    #+#             */
/*   Updated: 2023/03/01 15:50:45 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(int fd, unsigned int nbr, char *base)
{
	int				shift;
	int				idx;
	unsigned char	digit;
	char			number[HEX_INT_MAX];

	shift = HEX_INT_MAX;
	idx = 0;
	if (nbr == 0)
		return (ft_write(fd, "0", 1));
	while (shift--)
	{
		digit = 0xf & (nbr >> (shift * NIBBLE));
		if (digit || idx)
			number[idx++] = base[digit];
	}
	return (ft_write(fd, number, idx));
}
