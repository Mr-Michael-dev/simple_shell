#include "shell.h"
/**
 *
 */
char **getpath(char *file)
{
	char *path_cpy, *Path_token, **filePath;
	char *delim = ":";
	char *path = _getenv("PATH");
	int i = 0;

	path_cpy = strdup(path);
	Path_token = strtok(path_cpy, delim);

	filePath = (char **)malloc(1024 * sizeof(char *));

	while (Path_token != NULL)
	{
		filePath[i] = malloc(strlen(file) + strlen(Path_token) + 2);
		strcpy(filePath[i], Path_token);
		strcat(filePath[i], "/");
		strcat(filePath[i], file);

		Path_token = strtok(NULL, delim);
		
		i++;
	}

	free(path_cpy);
	return (filePath);
}
