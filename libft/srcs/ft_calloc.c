/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:46:04 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 17:51:58 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	bytes;
	void	*res;

	i = 0;
	bytes = count * size;
	res = NULL;
	res = malloc(bytes);
	if (!res)
		return (NULL);
	while (i < bytes)
	{
		((unsigned char *)res)[i] = 0;
		i++;
	}
	return (res);
}
