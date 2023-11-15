#include "shell.h"
/**
 * _chdir - change the current working directory of the shell process
 * @arg: argument vector
 *
 * Return: Nothing.
 */
void _chdir(char **arg)
{
	if (arg[1] == NULL)
	{
		chdir(_getenv("HOME"));
	}
	else
	{
		if (chdir(arg[1]) != 0)
		{
			fprintf(stderr, "cd: %s: %s\n", arg[1], strerror(errno));
		}
	}

	free_mem(arg);

}
