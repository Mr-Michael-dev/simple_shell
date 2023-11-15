#include "shell.h"
int main(void);
/**
 * main - entrypoint to the shell
 *
 * Return: 0 always
 */
int main(void)
{
	char *line_buf = NULL, *line_cpy;
	size_t buf_len = 0;
	char **arg = NULL;
	char *arg_delim = " \n";
	char *full_path;
	int status;

	if (isatty(STDIN_FILENO))
	{
		printf("#gmsh$ ");
	}

	while ((getline(&line_buf, &buf_len, stdin)) != EOF)
	{
		line_cpy = strdup(line_buf);
		if (line_cpy == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		if (strspn(line_cpy, " \t\r\n") == strlen(line_cpy))
		{
			free(line_cpy);
		}
		else
		{
			arg = tokenize(line_cpy, arg_delim);

			if (strcmp(arg[0], "exit") == 0)
			{
				status = EXIT_SUCCESS;

				if (arg[1])
					status = atoi(arg[1]);

				free_mem(arg);
				free(line_cpy);
				free(line_buf);
				exit(status);

			}

			else if (strcmp(arg[0], "cd") == 0)
				_chdir(arg);

			else if (strcmp(arg[0], "env") == 0)
			{
				_printenv();
				free_mem(arg);
			}
			else if (access(arg[0], X_OK) == 0)
			{
				child_process(arg[0], arg);
				free_mem(arg);
			}
			else
			{
				full_path = getpath(arg[0]);
				if (full_path != NULL)
				{
					child_process(full_path, arg);
					free_mem(arg);
					free(full_path);
				}
				else
				{
					fprintf(stderr, "./hsh: %d: %s\n", errno, strerror(errno));
					free_mem(arg);
					free(full_path);
				}

			}
			free(line_cpy);
		}

		if (isatty(STDIN_FILENO))
			printf("#gmsh$ ");
	}

	free(line_buf);
	if (isatty(STDIN_FILENO))
		printf("\n");
	return (0);
}
