/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:13:58 by gylim             #+#    #+#             */
/*   Updated: 2023/03/01 15:50:45 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_addr(int fd, void *addr)
{
	int				shift;
	int				idx;
	unsigned char	digit;
	char			address[HEX_LONG_MAX + 2];

	shift = HEX_LONG_MAX;
	idx = 0;
	address[0] = '0';
	address[1] = 'x';
	if (!addr)
		return (ft_write(fd, "0x0", 3));
	while (shift--)
	{
		digit = 0xf & ((unsigned long)addr >> (shift * NIBBLE));
		if (digit || idx)
			address[2 + idx++] = HEX_LOWER[digit];
	}
	return (ft_write(fd, address, idx + 2));
}
