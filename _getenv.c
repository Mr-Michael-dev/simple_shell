#include "shell.h"

extern char **environ;

char *_getenv(const char *name)
{
	int i;
	char *token;

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");

		if (token == NULL)
		{
			continue;
		}

		if (strcmp(name, token) == 0)
		{
			token = strtok(NULL, " \n");
			return (token);
		}
	}

	return (NULL);

}
