#include <stdio.h>
#include <string.h>

extern char **environ;
/**
 *
 *
 *
 */
void _env(void)
{
	int i; 

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}

}
