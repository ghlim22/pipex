/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:16:08 by gylim             #+#    #+#             */
/*   Updated: 2022/12/20 14:52:13 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}	
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}
