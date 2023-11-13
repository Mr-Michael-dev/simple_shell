#include "shell.h"

/**
 *
 *
 *
 */
void _printenv(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
