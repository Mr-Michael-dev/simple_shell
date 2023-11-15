#include "shell.h"
/**
 * exit_handler - cleanup function
 * @arg: argument vector
 * @line_buf: character array from the user
 * @line_cpy: copy of the character array from the user
 *
 * Return: Nothing.
 */
void exit_handler(char **arg, char *line_cpy, char *line_buf)
{
	free_mem(arg);
	free(line_cpy);
	free(line_buf);
	exit(0);
}
