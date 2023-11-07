#include "shell.h"
/**
 * free_mem - free the  allocated memory
 * @arg: string of arguments
 *
 * Return: Nothing
 */
void free_mem(char **arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if  (arg[i] != NULL)
			free(arg[i]);
	}

	if (arg != NULL)
		free (arg);
}

