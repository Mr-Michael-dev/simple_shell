#include "shell.h"

/**
 * tokenize - tokenize a char string into array of strings
 * @line: string to be tokenized
 * @delim: delimeter
 *
 * Return: array of strings a
 */

char **tokenize(char *line, char *delim)
{
	char **arg, *token;
	int i = 0;

	arg = (char **)malloc(101 * sizeof(char *));

	token = strtok(line, delim);

	while (token != NULL)
	{
		arg[i] = malloc(strlen(token) + 1);
		strcpy(arg[i++], token);
		token = strtok(NULL, delim);
	}
	arg[i] = NULL;
	i = 0;

	return (arg);
}
