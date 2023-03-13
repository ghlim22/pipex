/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:03:43 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 17:52:57 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*res;

	res = NULL;
	len = ft_strlen(s1);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
	{
		return (NULL);
	}
	ft_memcpy(res, s1, len);
	res[len] = '\0';
	return (res);
}
