#include "shell.h"
/**
 *
 */

char *getpath(char *file)
{
	char *path_cpy, *Path_token, *filePath;
	char *delim = ":";
	char *path = _getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found.\n");
		free(path);
		return (NULL);
	}

	path_cpy = strdup(path);
	free(path);
	if (path_cpy == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	Path_token = strtok(path_cpy, delim);

	while (Path_token != NULL)
	{
		filePath = malloc(strlen(Path_token) + strlen(file) + 2);
		if (filePath == NULL)
		{
			perror("malloc");
			free(path_cpy);
			return (NULL);
		}

		strcpy(filePath, Path_token);
		strcat(filePath, "/");
		strcat(filePath, file);

		if (access(filePath, X_OK) == 0)
		{
			free(path_cpy);
			return (filePath);
		}

		free(filePath);
		Path_token = strtok(NULL, delim);
	}

	free(path_cpy);
	return (NULL);
}

