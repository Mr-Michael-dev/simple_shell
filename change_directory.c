#include "shell.h"
/**
 * _chdir - change the current working directory of the shell process
 * @arg: argument vector
 *
 * Return: Nothing.
 */
void _chdir(char **arg)
{
	char *home;

	if (arg[1] == NULL)
	{
		home = _getenv("HOME");
		if (home == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return;
		}

		if (chdir(home) != 0)
		{
			fprintf(stderr, "cd: %s: %s\n", arg[1], strerror(errno));
		}
		free(home);
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
