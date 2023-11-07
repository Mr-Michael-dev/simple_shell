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
	char *line_cpyi, token;
	int counter;
	char **argv;
	/*pid_t child_pid;*/

	printf("#gmsh$ ");

	while ((getline(&line_buf, &buf_len, stdin)) != EOF)
	{
		line_cpy = strdup(line_buf);
		printf("%s\n", line_cpy);

		printf("#gmsh$ ");
		argv = (10 * sizeof(char *));
		token = strtok(lin_buff, " \n");
		while (token != NULL)
		{
			argv[i] = malloc(sizeof(char *) * (strlen(token) + 1));
			token = str
				conter++;
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;

		free(line_buf);
		free(line_cpy);
		line_buf = NULL;
		buf_len = 0;
	}

	printf("\n");
	return (0);
}
