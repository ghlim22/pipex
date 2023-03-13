/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:01:55 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 14:19:48 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (len-- && ft_strncmp(haystack, needle, needle_len) != 0)
	{
		if (!*haystack || len < needle_len)
			return (NULL);
		haystack++;
	}
	if (len + 1 < needle_len)
		return (NULL);
	return ((char *)haystack);
}
