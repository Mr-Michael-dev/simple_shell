#include "shell.h"

/**
 * child_process - creates a child process, execute user command  and wait.
 *
 * Return: 0 always
 */

void child_process(char **arg)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free_mem(arg);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execute(arg);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
	}

}
