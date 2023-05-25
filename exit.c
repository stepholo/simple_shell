#include "main.h"

/**
* exit_error_message - Handle error message for exit
* @av: Command name
* @arg: command name argument
* @line_number: line number of the command
* Return: void
*/
void exit_error_message(char *av, int line_number, char *arg)
{
	char *msg;
	char line_number_str[12];
	int len;

	len = _strlen(av) + _strlen(arg) + 32;
	msg = malloc(len);
	if (msg == NULL)
	{
		perror("malloc failed");
		exit(2);
	}

	_strcpy(msg, av);
	_strcat(msg, ": ");

	_sprintf(line_number_str, line_number);
	_strcat(msg, line_number_str);
	_strcat(msg, ": exit: Illegal number: ");

	_strcat(msg, arg);
	_strcat(msg, "\n");

	write(STDERR_FILENO, msg, _strlen(msg));
	free(msg);
}

/**
* validate_exit_argument - Validates exit command arguments
* @arg: Exit command argument
* Return: true for valid argument, false othersiwe
*/
bool validate_exit_argument(const char *arg)
{
	char *endptr;
	long int exit_code;

	exit_code = strtol(arg, &endptr, 10);
	return (*endptr == '\0' && exit_code >= 0);
}

/**
* handle_exit - Handles the exit command return status
* @args: command argument
* @command: User input
* Return: exits with 2 for valid argument and 0 for exit
*/
void handle_exit(char **args, char *command)
{
	int exit_status = 0;

	if (args[1] == NULL)
	{
		cleanup(args, command);
		exit(exit_status);
	}

	if (!validate_exit_argument(args[1]))
	{
		exit_status = 2;
		exit_error_message("./hsh", 1, args[1]);
		cleanup(args, command);
		exit(exit_status);
	}

	exit_status = _atoi(args[1]);
	if (exit_status > 255)
		exit_status %= 256;
	cleanup(args, command);
	exit(exit_status);
}
