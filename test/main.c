#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
	/*
	pid_t 	pid;
	int		stat;
	pid = fork();
	if (pid == 0)
	{
		sleep(10);
		printf("child end...\n");
		return (0);
	}
	while (wait(&stat) == 0)
	{
		printf("waiting...\n");
	}
	printf("parent end...\n");
	*/

	for (int i = 0; envp[i]; ++i)
		printf("%s\n", envp[i]);
	
	int w = 7;

	int x = *(int *) & w;
	printf("%d", x);
	return (0);
}