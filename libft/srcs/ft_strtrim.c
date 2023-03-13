/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:13:11 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 17:53:21 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*start;
	char	*end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (!len)
		return (ft_strdup(""));
	start = (char *)s1;
	end = (char *)s1 + len - 1;
	while (start <= s1 + len && check_set(*start, set))
		start++;
	while (end >= s1 && check_set(*end, set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, start, len + 1);
	return (res);
}

static int	check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
