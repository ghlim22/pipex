/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:33:36 by gylim             #+#    #+#             */
/*   Updated: 2023/03/01 18:27:21 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../libft/includes/libft.h"
#define ARGC_MSG ("usage: ./pipex file1 cmd1 cmd2 file2\n")

static void	check_file(const char *pathname, int mode)
{
	if (access(pathname, mode) == -1)
	{
		ft_printf(STDERR_FILENO, "pipex: %s: %s\n", strerror(errno), pathname);
		//perror("pipex");
		exit(EXIT_FAILURE);
	}
}

static void	check_argc(int argc)
{
	if (argc != 5)
	{
		ft_printf(STDERR_FILENO, ARGC_MSG);
		exit(EXIT_FAILURE);
	}
}

static void	set_io(char **argv)
{
	int	infile;
	int	outfile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1 || dup2(infile, STDIN_FILENO) == -1)
	{
		perror("pipex: ");
		exit(EXIT_FAILURE);
	}
	outfile = open(argv[4], O_CREAT | O_WRONLY, 0644);
	if (outfile == -1 || dup2(outfile, STDOUT_FILENO) == -1)
	{
		close(infile);
		perror("pipex: ");
		exit(EXIT_FAILURE);
	}	
}

int	main(int argc, char **argv)
{
	check_argc(argc);
	check_file(argv[1], F_OK | R_OK);
	set_io(argv);

	
	/*
	char *str = get_next_line(STDIN_FILENO);
	while (str)
	{
		ft_printf(STDOUT_FILENO, "%s", str);
		str = get_next_line(STDIN_FILENO);
	}
	*/

	return (0);
}
