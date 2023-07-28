#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *string_copy(char *dest, const char *src);
int executecommands(char **argv);
int string_lenght(char *c);
int string_compare(const char *string1, const char *string2);
char *string_concatenate(char *destination, char *src);
int empty_line(char *command);
void _env(void);
char **_split(char *str, char *sep);
void *_calloc(unsigned int nmemb, unsigned int size);



extern char **environ;

#endif
