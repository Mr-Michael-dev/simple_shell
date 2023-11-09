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

char **tokenize(char *line, char *delim);

void execute(char *arg[]);

void child_process(char **arg);

char *location(char *path, char *arg);

 char *get_loc(char *arg);

#endif /*SHELL_H*/
