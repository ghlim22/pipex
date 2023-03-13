/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:58:55 by gylim             #+#    #+#             */
/*   Updated: 2023/03/01 15:50:45 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(int fd, char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_write(fd, NULL_PROMPT, 6));
	while (*str++)
		++len;
	return (ft_write(fd, str - len - 1, len));
}
