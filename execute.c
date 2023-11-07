#include "shell.h"
/**
 * execute - executes new program in the current process
 * @arg: argument vector
 *
 * Return: Nothing, -1 on error
 */
void execute(char *arg[])
{ 
	if (execve(arg[0], arg, NULL) == -1)
		perror("Error");
}
