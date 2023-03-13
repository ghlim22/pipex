/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:03:49 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 17:53:05 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_first;
	size_t	len_second;
	size_t	len_total;

	res = NULL;
	if (!s1 || !s2)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s2));
	if (!*s2)
		return (ft_strdup(s1));
	len_first = ft_strlen(s1);
	len_second = ft_strlen(s2);
	len_total = len_first + len_second;
	res = (char *)malloc((len_total + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (const char *)s1, len_total + 1);
	ft_strlcat(res, (const char *)s2, len_total + 1);
	return (res);
}
