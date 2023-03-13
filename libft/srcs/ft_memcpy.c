/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:25:16 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 18:26:42 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*to;
	unsigned char	*from;

	if (!dst && !src)
		return (NULL);
	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dst);
}
