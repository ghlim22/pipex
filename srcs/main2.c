/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:33:36 by gylim             #+#    #+#             */
/*   Updated: 2023/03/03 19:58:53 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../libft/includes/libft.h"
#define USAGE_MSG ("usage: ./pipex file1 cmd1 cmd2 file2\n")
#define READ (0)
#define WRITE (1)

enum	e_return_val
{
	SUCCESS = 0,
	FAIL = -1
};

typedef struct	s_comm
{
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd1;
	char	**cmd2;

}	t_comm;
/*
static void	check_infile(const char *pathname, int mode)
{
	if (access(pathname, mode) == -1)
	{
		//ft_printf(STDERR_FILENO, "pipex: %s: %s\n", strerror(errno), pathname);
		perror("pipex");
		exit(EXIT_FAILURE);
	}
}

static void	check_argc(int argc)
{
	if (argc != 5)
	{
		ft_printf(STDERR_FILENO, USAGE_MSG);
		exit(EXIT_FAILURE);
	}
}

static void	set_io(char **argv)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1 || dup2(infile, STDIN_FILENO) == -1)
	{
		perror("pipex: ");
		exit(EXIT_FAILURE);
	}
}
*/

static int destory_strings(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (SUCCESS);
}

static int try_split(char ***arr, const char *s, char c)
{
	*arr = ft_split(s, c);
	if (*arr == NULL)
		return (FAIL);
	return (SUCCESS);
}

static int get_cmd1(char **path, char **argv, t_comm *comm)
{
	char	*tmp;
	int		i;

	if (FAIL == try_split(&comm->cmd1, argv[2], ' '))
		return (FAIL);
	for (int j = 0; comm->cmd1[j]; ++j)
		printf("%s\n", comm->cmd1[j]);
	comm->cmd1_path = (char *)NULL;
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], comm->cmd1[0]);
		if (NULL == tmp && destory_strings(comm->cmd1))
			return (FAIL);
		if (SUCCESS == access(tmp, F_OK | X_OK))
		{
			comm->cmd1_path = tmp;
			break ;
		}
		free(tmp);
		++i;
	}
	if (NULL == comm->cmd1_path)
		return (FAIL);
	return (SUCCESS);
}

static int get_cmd2(char **path, char **argv, t_comm *comm)
{
	char	*tmp;
	int		i;

	if (FAIL == try_split(&comm->cmd2, argv[3], ' '))
		return (FAIL);
	for (int j = 0; comm->cmd2[j]; ++j)
		printf("%s\n", comm->cmd2[j]);
	comm->cmd2_path = (char *)NULL;
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], comm->cmd2[0]);
		if (NULL == tmp && destory_strings(comm->cmd2))
			return (FAIL);
		if (SUCCESS == access(tmp, F_OK | X_OK))
		{
			comm->cmd2_path = tmp;
			break ;
		}
		free(tmp);
		++i;
	}
	if (NULL == comm->cmd1_path)
		return (FAIL);
	return (SUCCESS);
}

static int	check_path(char **argv, char **envp, t_comm *comm)
{
	char	**path;
	int		i;
	int		j;

	(void)argv;
	(void)comm;
	
	i = 0;
	while (envp[i] && !ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (NULL == envp[i] || FAIL == try_split(&path, envp[i] + 5, ':'))
		return (FAIL);
	i = 0;
	while (path[i])
	{
		if (!append(&path[i], "/") && destory_strings(path))
			return (FAIL);
		++i;
	}
	for (j = 0; path[j]; ++j)
		ft_printf(STDOUT_FILENO, "%s\n", path[j]);
	printf("argv[2]: %s\n", argv[2]);
	if (FAIL == get_cmd1(path, argv, comm) || FAIL == get_cmd2(path, argv, comm))
	{
		destory_strings(path);
		return (FAIL);
	}
	ft_printf(STDOUT_FILENO, "%s\n", comm->cmd1_path);
	ft_printf(STDOUT_FILENO, "%s\n", comm->cmd2_path);	
	return (SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	//check_infile(argv[1], F_OK | R_OK);
	(void)argc;
	(void)argv;
	(void)envp;
	t_comm *comm;

	comm = (t_comm *)malloc(sizeof(t_comm));
	if (NULL == comm)
		return (0);
	check_path(argv, envp, comm);
	return (0);
}
