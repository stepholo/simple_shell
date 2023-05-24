#ifndef SHELL_H
#define SHELL_H

/* Defined macros used */
#define MAX_ARGUMENTS 10
#define BUFFER_SIZE 1024

/* Standard library header files used */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

/* Global variables used */
extern char **environ;
extern char **av;
extern char *command;
extern char **args;
extern bool should_exit;

/* Shell Implementation */
int run_command(char *command, char **args, char **envp,
		char **av, int line_number);
int execute_command(char *path, char **args, char **envp);
char **parse_arguments(char *command);
char *find_command_path(char *command);
char *build_full_path(char *start, char *command);

/* Shell inbuit command */
int inbuilt_command(char *command, char **args, char **envp, char **av);
int exit_builtin(char **args);
bool validate_exit_argument(const char *arg);
void handle_exit(char **args, char *command);
int env_builtin(char **args);
int cd(char **args);

/* User defined getline function */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* Error messages */
void error_message(char *avO, int line_number, char *argO);
void exit_error_message(char *av, int line_number, char *arg);
void cd_error_message(char *av, int line_number, char *dir);

/* handles string prototypes*/
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
void rev_str(char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
char *_strcat(char *dest, const char *src);
char *_strchr(const char *str, int ch);
int _atoi(const char *str);
unsigned int _strspn(char *str, const char *accept);
size_t _strcspn(char *str, const char *reject);
char *_strtok(char *str, const char *del, char **pos);

/* Handle memory */
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size);
void cleanup(char **args, char *command);
char *_memset(char *str, char x, unsigned int val);

/* User defined function */
char *_getenv(char *name, char **envp);
void _sprintf(char *str, int num);

#endif /* SHELL_H */
