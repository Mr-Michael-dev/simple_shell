#include "shell.h"
/**
 * execute - executes new program in the current process
 * @arg: argument vector
 *
 * Return: Nothing
 */
void execute(char *arg[])
{
	if (execve(arg[0], arg, NULL) == -1)
	{
		fprintf(stderr, "%s: %s\n", arg[0], strerror(errno));
		exit(EXIT_FAILURE);
	}
}
