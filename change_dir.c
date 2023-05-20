#include "main.h"

/**
* cd_error_message - Handle error messages for cd command
* @av: command name
* @line_number: line number of the command
* @dir: directory that couldn't be accessed
* Return: void
*/
void cd_error_message(char *av, int line_number, char *dir)
{
	char *msg;
	char line_number_str[12];
	int len;

	len = _strlen(av) + _strlen(dir) + 28;
	msg = malloc(len);
	if (msg == NULL)
	{
		perror("malloc failed");
		exit(2);
	}

	_strcat(msg, "./hsh");
	_strcat(msg, ": ");

	_sprintf(line_number_str, line_number);
	_strcat(msg, line_number_str);
	_strcat(msg, ": cd: can't cd to ");

	_strcat(msg, dir);
	_strcat(msg, "\n");

	write(STDERR_FILENO, msg, _strlen(msg));
	free(msg);
}

/**
* cd - Implementation of change directory
* @args: Directory to change to
* Return: 0
*/
int cd(char **args)
{
	char *dir = args[1];
	char *home_dir = _getenv("HOME", environ);
	char *prev_dir = _getenv("PWD", environ);
	int ret;

	if (dir == NULL || *dir == '~')
	{
		dir = home_dir;
	}

	else if (*dir == '-')
	{
		dir = prev_dir;
	}

	ret = chdir(dir);
	if (ret != 0)
	{
		cd_error_message(args[0], 1, dir);
		return (1);
	}

	setenv("PWD", dir, 1);

	return (0);
}
