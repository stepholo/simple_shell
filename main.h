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
int inbuilt_command(char *command, char **args, char **envp, char *av);
int exit_builtin(char **args);
bool validate_exit_argument(const char *arg);
void handle_exit(char **args, char *command);
int env_builtin(char **args);

/* Error messages */
void error_message(char *avO, int line_number, char *argO);
void exit_error_message(char *av, int line_number, char *arg);

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

/* Handle memory */
void cleanup(char **args, char *command);

/* User defined function */
char *_getenv(char *name, char **envp);
void _sprintf(char *str, int num);

#endif /* SHELL_H */
