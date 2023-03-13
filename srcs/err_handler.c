/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:58:14 by gylim             #+#    #+#             */
/*   Updated: 2023/03/12 21:03:31 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_x.h"
#include "../libft/include/libft.h"
#include <stdio.h> /* for perror() */
#include <stdlib.h> /* for exit() */

void	print_usage_exit(void)
{
	ft_printf(2, "pipex: usage: ./pipex file1 cmd1 cmd2 file2\n");
	exit(EXIT_FAILURE);
}
