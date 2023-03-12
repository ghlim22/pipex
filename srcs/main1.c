/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:00:11 by gylim             #+#    #+#             */
/*   Updated: 2023/03/05 20:38:44 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

enum e_return
{
	SUCCESS = 0,
	FAIL = -1
};

typedef struct	s_comm
{
	int		cmd_cnt;
	char	**cmd_paths;
	int		infile;
	int		outfile;
	int		pipe_fd[2];
}				t_comm;

void	ppx_perr_exit(const char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

static int try_split(char ***arr, const char *s, char c)
{
	*arr = ft_split(s, c);
	if (*arr == NULL)
		return (-1);
	return (0);
}

void	check_path(char **argv, char **envp, t_comm *comm)
{
	char	**path;
	int		i;
	int		j;

	i = 0;
	while (envp[i] && !ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i] || try_split(&path, envp[i], ':'))
	{
		destroy_comm(comm);
	}
}

void	check_files(int argc, char **argv, t_comm *comm)
{
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		free(comm);
		ppx_perr_exit("pipex", EXIT_FAILURE);
	}
	comm->infile = open(argv[1], O_RDONLY);
	if (comm->infile == -1)
	{
		destroy_comm(comm);
		ppx_perr_exit("pipex", EXIT_FAILURE);
	}
	comm->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (comm->outfile == -1)
	{
		destroy_comm(comm);
		ppx_perr_exit("pipex", EXIT_FAILURE);
	}
}

void	allocate_comm(t_comm **comm, int argc, char **argv, char **envp)
{
	int	i;

	*comm = (t_comm *)malloc(sizeof(t_comm));
	if (!*comm)
		ppx_perr_exit("pipex", EXIT_FAILURE);
	(*comm)->cmd_cnt = argc - 3;
	(*comm)->cmd_paths = (char **)malloc(sizeof(char *) * (argc - 3));
	if (!((*comm)->cmd_paths))
	{
		free(*comm);
		ppx_perr_exit("pipex", EXIT_FAILURE);
	}
	i = -1;
	while (++i < (*comm)->cmd_cnt)
		(*comm)->cmd_paths[i] = NULL;
}

void	destroy_comm(t_comm *comm)
{
	int	i;

	i = 0;
	while (i < comm->cmd_cnt)
	{
		if (comm->cmd_paths[i])
			free(comm->cmd_paths[i]);
		++i;
	}
	free(comm->cmd_paths);
	free(comm);
}



int	main(int argc, char **argv, char **envp)
{
	t_comm	*comm;

	if (argc != 5)
		ppx_perr_exit("usage: ./pipex infile cmd1 cmd2 outfile", EXIT_SUCCESS);
	comm = (t_comm *)malloc(sizeof(t_comm));
	if (!comm)
		ppx_perr_exit("malloc error", EXIT_FAILURE);
	
	
	
}