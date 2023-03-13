/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:42:44 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 14:17:56 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	niddle;

	niddle = (char)c;
	while (*s)
	{
		if (niddle == *s)
			return ((char *)s);
		s++;
	}
	if (niddle == *s)
		return ((char *)s);
	return (NULL);
}
