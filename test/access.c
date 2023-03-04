#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int mode;

	mode = 0;
	mode |= F_OK;
	if (!access("output.txt", mode))
		printf("File is existing.\n");
	else
		printf("File is not existing.\n");
	mode &= 0;
	mode |= X_OK;
	if (!access("output.txt", X_OK))
		printf("File is executable.\n");
	else
		printf("File is not executable.\n");
	return (0);
}