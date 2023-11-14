#include "shell.h"
/**
 * _printenv - prints then enviroment varaible to the stdout
 *
 * Return: Nothing
 */
void _printenv(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
