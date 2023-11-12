#include <stdio.h>
#include <string.h>

extern char **environ;
/**
 *
 *
 *
 */
char *_getenv(const char *name)
{
	int i;
	char *token;
	char *value;

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");

		if (token == NULL)
		{
			continue;
		}

		if (strcmp(name, token) == 0)
		{
			value = environ[i] + strlen(token) + 1;
			return (strdup(value));
		}
	}

	return (NULL);
}
