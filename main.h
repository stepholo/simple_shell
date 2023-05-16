#ifndef SHELL
#define SHELL

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/* handles string prototypes*/
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
void rev_str(char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
char *_strcat(char *dest, const char *src);
char *_strchr(const char *str, int ch);
#endif
