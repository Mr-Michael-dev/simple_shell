#include "shell.h"
/**
 * _getenv - retrieve the value of a specific enviroment variable
 * @name: name of the enviroment variable to retrieve
 *
 * Return: the value of the variable, NULL on error
 */
char *_getenv(const char *name)
{
	int i;
	char *value;
	char *equals;
	char *key;

	for (i = 0; environ[i] != NULL; i++)
	{
		equals = strchr(environ[i], '=');
		if (equals != NULL)
		{
			key = strndup(environ[i], equals - environ[i]);
			if (strcmp(name, key) == 0)
			{
				value = strdup(equals + 1);
				free(key);
				return (value);
			}
			free(key);
		}
	}

		return (NULL);
}
