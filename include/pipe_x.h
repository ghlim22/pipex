/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_x.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:55:02 by gylim             #+#    #+#             */
/*   Updated: 2023/03/12 21:03:39 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_X
# define PIPE_X

typedef struct	s_comm
{
	int		idx;
	int		commands_cnt;
	char	**path;
}				t_comm;

void	print_usage_exit(void);

#endif