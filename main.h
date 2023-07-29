#ifndef _MAIN_H_
#define _MAIN_H_

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
int testifempty(char *command);
void getenvironment(void);
char **splt_str(char *str, char *sep);
void *allocate(unsigned int nmemb, unsigned int size);
char *get_pth(char *cmd);
char *getenviron(char *env);

extern char **environ;

#endif
