#include "main.h"

/**
* cd_error_message - Handle error messages for cd command
* @line_number: line number of the command
* @dir: directory that couldn't be accessed
* Return: void
*/
void cd_error_message(int line_number, char *dir)
{
	char line_number_str[12];

	_sprintf(line_number_str, line_number);
	fprintf(stderr, "./hsh: %s: cd: can't cd to %s\n", line_number_str, dir);
}

/**
* cd - Implementation of change directory
* @args: Directory to change to
* @line_number: command line number
* Return: 0
*/
int cd(char **args, int line_number)
{
	char *dir = args[1];
	char *home_dir = _getenv("HOME", environ);
	char *prev_dir = _getenv("PWD", environ);
	char *current_dir = _getenv("PWD", environ);
	int ret;

	if (dir == NULL || *dir == '~')
	{
		dir = home_dir;
	}

	else if (*dir == '-')
	{
		dir = prev_dir;
		_puts(current_dir);
		_puts("\n");
	}

	ret = chdir(dir);
	if (ret != 0)
	{
		cd_error_message(line_number, dir);
		return (1);
	}

	_setenv("PWD", dir, 1);

	return (0);
}
