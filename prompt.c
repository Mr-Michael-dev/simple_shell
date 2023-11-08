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
	pid_t child_pid;

	do {
		printf("#gmsh$ ");
		if ((getline(&line_buf, &buf_len, stdin)) == EOF)
		{
			break;
		}

		line_cpy = strdup(line_buf);
		if (line_cpy == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		arg = tokenize(line_cpy);
		if (arg == NULL)
		{
			perror("tokenize");
			free(line_cpy);
			continue;
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			free_mem(arg);
			free(line_cpy);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			execute(arg);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}

		free_mem(arg);
		free(line_buf);
		free(line_cpy);
		line_buf = NULL;
		buf_len = 0;
	} while (1);
	free(line_buf);
	printf("\n");
	return (0);
}
