#include "shell.h"
/**
 *
 */
char *location(char *path, char *arg)
{
	char *path_cpy, *Path_token, *filePath;
	char *delim = ":";

	path_cpy = strdup(path);

	Path_token = strtok(path_cpy, delim);

	while (Path_token != NULL)
	{
		filePath = malloc(strlen(arg) + strlen(Path_token) + 2);
		strcpy(filePath, Path_token);
		strcat(filePath, "/");
		strcat(filePath, arg);
		strcat(filePath, "\0");


		if (stat(filePath,&buffer) == 0)
		{
			free(path_cpy);
			return filePath;
		}
		free(filePath);
		Path_token = strtok(NULL, delim);
	}

	free(path_cpy);
	return (NULL);
}

char *get_loc(char *arg)
{
	char *path;

	path = (access("PATH", X_OK) == 0);

	if (path)
	{
		return (location(path, arg));
	}

	return (NULL);
}
