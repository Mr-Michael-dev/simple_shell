#include "shell.h"
/**
 * execute - executes new program in the current process
 * @path: path to the executable file
 * @arg: argument vector
 *
 * Return: Nothing
 */
void execute(char *path, char **arg)
{

	if (execve(path, arg, environ) == -1)
	{
		fprintf(stderr, "%s: %s\n", arg[0], strerror(errno));
		exit(EXIT_FAILURE);
	}
}
