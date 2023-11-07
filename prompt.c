#include "shell.h"

/**
 * main - entrypoint to the shell
 *
 * Return: 0 always
 */

int main(void)
{
	char *line_buf = NULL;
	size_t buf_len = 0;
	char *line_cpy, *token;
	int counter, i;
	char **a;
	/*pid_t child_pid;*/

	(void)counter;
	printf("#gmsh$ ");

	while ((getline(&line_buf, &buf_len, stdin)) != EOF)
	{
		line_cpy = strdup(line_buf);
		printf("%s\n", line_cpy);

		printf("#gmsh$ ");
		a = (char **)malloc(101 * sizeof(char *));
		token = strtok(line_buf, " \n");
		while (token != NULL)
		{
			a[i] = malloc(strlen(token) + 1);
			strcpy(a[i], token);
			i++;
			token = strtok(NULL, " \n");
		}
		a[i] = NULL;

		free_mem(a);

		free(line_buf);
		free(line_cpy);
		line_buf = NULL;
		buf_len = 0;
	}

	printf("\n");
	return (0);
}
