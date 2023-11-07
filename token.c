#include "shell.h"

/**
 * tokenize - tokenize a char string into array of strings
 * @line: string to be tokenized
 *
 * Return: array of strings a
 */

char **tokenize(char *line)
{
	char **arg, *token;
	int i = 0;

	arg = (char **)malloc(101 * sizeof(char *));
	
	token = strtok(line, " \n");

	while (token != NULL)
	{
		arg[i] = malloc(strlen(token) + 1);
		strcpy(arg[i++], token);
		token = strtok(NULL, " \n");
	}
	arg[i] = NULL;

	return (arg);
}
