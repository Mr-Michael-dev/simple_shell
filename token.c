#include "shell.h"

/**
 * tokenize - tokenize a char string into array of strings
 * @line: string to be tokenized
 *
 * Return: array of strings a
 */

char **tokenize(char *line)
{
	char **a, *token;
	int i = 0;

	a = (char **)malloc(101 * sizeof(char *));
	
	token = strtok(line, " \n");

	while (token != NULL)
	{
		a[i] = malloc(strlen(token) + 1);
		strcpy(a[i++], token);
		token = strtok(NULL, " \n");
	}
	a[i] = NULL;

	return (a);
}
