/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:13:52 by gylim             #+#    #+#             */
/*   Updated: 2023/03/01 17:26:54 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static size_t	len(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*duplicate(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dup;

	len = 0;
	while (src[len])
		++len;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = src[i];
		++i;
	}
	return (dup);
}

char	*split(char **storage)
{
	char	*temp_storage;
	char	*line;
	size_t	len;
	size_t	i;

	temp_storage = *storage;
	len = 0;
	while ((*storage)[len] != '\n')
		++len;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = (*storage)[i];
		++i;
	}
	line[i++] = '\n';
	line[i] = '\0';
	*storage = duplicate(*storage + len + 1);
	free(temp_storage);
	return (line);
}

static void	copy(char *dst, char *src1, char *src2)
{
	while (*src1)
	{
		*dst = *src1;
		dst++;
		src1++;
	}
	while (*src2)
	{
		*dst = *src2;
		dst++;
		src2++;
	}
	*dst = '\0';
}

int	append(char **original, char *addition)
{
	char	*temp_original;
	char	*res;

	if (!*original || !addition)
		return (0);
	temp_original = *original;
	res = (char *)malloc(sizeof(char) * (len(*original) + len(addition) + 1));
	if (!res)
		return (0);
	copy(res, *original, addition);
	*original = res;
	free(temp_original);
	return (1);
}
