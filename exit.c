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
* exit_builtin - exits the shell
* @args: array of arguments passed to the exit command
* Return: always 0, to signall the shell to exit
*/
int exit_builtin(char **args)
{
	int i = 0, status = 0;

	args[0] = "./hsh";

	if (args[1] != NULL)
	{
		if (args[1][0] == '-')
		{
			exit_error_message(args[0], 1, args[1]);
			exit(2);
		}

		while (args[1][i] != '\0')
		{
			if (arg[1][i] < '0' || args[1][i] > '9')
			{
				exit_error_message(args[0], 1, args[1]);
				exit(2);
			}

			status = status * 10 + (args[1][i] - '0');
			i++;
		}
	}

	if (status < 0)
	{
		exit_error_message(args[0], 1, args[1]);
		exit(2);
	}

	exit(status);
	return (0);
}

