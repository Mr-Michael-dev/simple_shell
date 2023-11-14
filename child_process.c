#include "shell.h"

/**
 * child_process - creates a child process, execute user command  and wait.
 * @arg: argument to be executed
 * @path: full path to the executeable
 *
 * Return: nothing
 */

void child_process(char *path, char **arg)
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
		/*free_mem(arg);*/
		execute(path, arg);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
	}

}
