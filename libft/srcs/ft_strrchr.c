/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:46:42 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 14:18:53 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	needle;
	char	*loc;
	size_t	i;
	size_t	len;

	loc = NULL;
	needle = (char)c;
	len = ft_strlen(s);
	i = 0;
	if (needle == '\0')
	{
		return ((char *)s + len);
	}
	while (i < len)
	{
		if (needle == *s)
			loc = (char *)s;
		i++;
		s++;
	}
	return (loc);
}
