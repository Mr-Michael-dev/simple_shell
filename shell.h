#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

void free_mem(char **arg);

char **tokenize(char *line);

void execute(char *arg[]);

#endif /*SHELL_H*/
