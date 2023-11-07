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
	char *line_cpy;
	int counter, i = 0;
	char **a;
	/*pid_t child_pid;*/

	(void)counter;
	printf("#gmsh$ ");

	while ((getline(&line_buf, &buf_len, stdin)) != EOF)
	{
		line_cpy = strdup(line_buf);
		a = tokenize(line_cpy);

		for (i = 0; a[i]; i++)
		{
			printf("%s\n", a[i]);
		}

		i = 0;
		printf("#gmsh$ ");
		free_mem(a);
		free(line_buf);
		free(line_cpy);
		line_buf = NULL;
		buf_len = 0;

	}

	free(line_buf);
	printf("\n");
	return (0);
}
