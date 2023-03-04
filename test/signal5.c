#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	print_handler(int sig)
{
	printf("Child: I got Signal %d.\n", sig);
}

int	main(void)
{
	pid_t	pid;
	pid_t 	ret;
	int		status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		signal(SIGCONT, print_handler);
		printf("Child: I will be stopped.\n");
		while (1)
			;
	}
	else
	{
		printf("Parent: I have a Child with pid %d.\n", pid);
		ret = waitpid(pid, &status, WUNTRACED);
		printf("Parent: Child has been stopped.\n");
		if (WIFSIGNALED(status))
			printf("Parent: Successfully got status from %d Child.\n", ret);
		if (WIFSTOPPED(status))
			printf("Parent: Exit Code is %d, Signal is %d.\n", WEXITSTATUS(status), WSTOPSIG(status));
		usleep(10000000);
		ret = waitpid(pid, &status, WCONTINUED | WNOHANG);
		printf("Parent: Child has been continued.\n");
		if (WIFSIGNALED(status))
			printf("Parent: Successfully got status from %d Child.\n", ret);
		if (WIFCONTINUED(status))
			printf("Parent: Exit Code is %d, Signal is %d.\n", WEXITSTATUS(status), WSTOPSIG(status));	
	}
	return (0);
}