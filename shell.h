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

void execute(char *path, char **arg);

void child_process(char *path, char **arg);

char *getpath(char *file);

char *_getenv(const char *name);

void _printenv(void);

void _chdir(char **arg);

extern char **environ;

#endif /*SHELL_H*/
