#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define PIPE_READ	(0)
#define PIPE_WRITE	(1)
#define BUFFER_SIZE	(4096)

void	child_command(void)
{
	int		ret;
	char	buffer[BUFFER_SIZE];

	ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));	
}

void	child_proc(int pipe[2])
{
	int	fd;
	int	r_fd;
	int	w_fd;

	printf("Child: I'm going to close fd for Read.\n");
	printf("Child: I'm going to connect STDOUT to fd for Write.\n");
	printf("Child: I'm going to connect STDIN to fd from a file.\n");
	printf("Child: Eventually I'll read from STDIN (file) and write to STDOUT (pipe).\n");
	close(pipe[PIPE_READ]);
	w_fd = dup2(pipe[PIPE_WRITE], STDOUT_FILENO);
	close(pipe[PIPE_WRITE]);
	if (w_fd == -1)
		exit(1);
	fd = open("read.txt", O_RDONLY);
	if (fd == -1)
		exit(1);
	r_fd = dup2(fd, STDIN_FILENO);
	close(fd);
	if (r_fd == -1)
		exit(1);
	child_command();
}

void	parent_command(void)
{
	int		ret;
	char	buffer[BUFFER_SIZE];

	ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));	
}

void	parent_proc(int pipe[2], pid_t pid)
{
	int	fd;
	int	r_fd;
	int	w_fd;

	printf("Parent: I'm going to close fd for Write.\n");
	printf("Parent: I'm going to connect STDIN to fd for Read.\n");
	printf("Parent: I'm going to connect STDOUT to fd from a file.\n");
	printf("Eventually I'll read from STDIN (pipe) and write to STDOUT (file).\n");
	close(pipe[PIPE_WRITE]);
	r_fd = dup2(pipe[PIPE_READ], STDIN_FILENO);
	close(pipe[PIPE_READ]);
	if (r_fd == -1)
		exit(1);
	fd = open("write.txt", O_WRONLY);
	if (fd == -1)
		exit(1);
	w_fd = dup2(fd, STDOUT_FILENO);
	close(fd);
	if (w_fd == -1)
		exit(1);
	if (waitpid(pid, NULL, 0) == -1)
		exit(1);
	parent_command();
}

int	main(void)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (1);
	printf("Parent: fd for Read is %d, fd for Write is %d.\n", fd[PIPE_READ], fd[PIPE_WRITE]);
	pid = fork();
	if (pid == -1)
	{
		close(fd[PIPE_READ]);
		close(fd[PIPE_WRITE]);
		return (1);
	}
	else if (!pid)
		child_proc(fd);
	else
		parent_proc(fd, pid);
	return (0);
}