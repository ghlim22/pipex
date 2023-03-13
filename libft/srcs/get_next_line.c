/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:31:39 by gylim             #+#    #+#             */
/*   Updated: 2023/03/01 17:27:02 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	find_linebreak(const char *s)
{
	while (*s)
	{
		if ('\n' == *s)
			return (1);
		s++;
	}
	return (0);
}

static ssize_t	store(int fd, char **storage)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		read_byte;

	read_byte = 1;
	while (read_byte && !find_linebreak(*storage))
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte <= 0)
			break ;
		buf[read_byte] = '\0';
		if (!append(storage, buf))
			return (-1);
	}
	return (read_byte);
}

static char	*read_line(int fd, char **storage)
{
	char	*line;
	ssize_t	read_byte;
	int		has_linebreak;

	if (!*storage)
		return (NULL);
	read_byte = store(fd, storage);
	if (read_byte == -1 || !**storage)
	{
		free(*storage);
		*storage = NULL;
		return (NULL);
	}
	has_linebreak = find_linebreak(*storage);
	if (has_linebreak)
		line = split(storage);
	else
		line = duplicate(*storage);
	if (!line || !has_linebreak)
	{
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;

	if (fd < 0)
		return (NULL);
	if (!storage)
		storage = duplicate("");
	return (read_line(fd, &storage));
}
