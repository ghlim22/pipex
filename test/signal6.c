#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid_t ret;
	int status;

	pid = fork();
	if(pid == -1)
		return (1);
	else if (!pid)
	{
		printf("Child: I will get some of a Signal.\n");
		while (1)
			;
	}
	else
	{
		printf("Parent: I have a Child with pid %d.\n", pid);
		ret = wait(&status);
		printf("Parent: Successfully got status from %d Child.\n", ret);
		if (WIFSIGNALED(status))
			printf("Parent: Exit code is %d, Signal is %d.\n", WEXITSTATUS(status), WTERMSIG(status));
	}
	return (0);
}