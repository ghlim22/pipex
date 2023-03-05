#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t	pid;
	pid_t	ret;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
		printf("Child: I will be exited.\n");
	else
	{
		printf("Parent: I have a Child with pid %d.\n", pid);
		ret = wait(NULL);
		printf("Parent: %d Child has been retrieved.\n", ret);
		while (1) ;
	}
	return (0);
}