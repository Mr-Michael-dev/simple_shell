#include "shell.h"

/**
 * main - entrypoint to the shell
 *
 * Return: 0 always
 */

int main(void)
{
	char *line_buf = NULL, *line_cpy;
	size_t buf_len = 0;
	char **arg;
	char *arg_delim = " \n";

	if (isatty(STDIN_FILENO))
	{
		printf("#gmsh$ ");
	}
	while ((getline(&line_buf, &buf_len, stdin)) != EOF)
	{
		line_cpy = strdup(line_buf);

		arg = tokenize(line_cpy, arg_delim);
		if (arg == NULL || strspn(line_cpy, " \t\r\n") == strlen(line_cpy))
		{
			free(line_cpy);
			free_mem(arg);
		}
		else
		{
			child_process(arg);
			free_mem(arg);
			free(line_buf);
			free(line_cpy);
			line_buf = NULL;
			buf_len = 0;
		}
		if (isatty(STDIN_FILENO))
			printf("#gmsh$ ");
	}

	free(line_buf);
	if (isatty(STDIN_FILENO))
		printf("\n");
	return (0);
}
