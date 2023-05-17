#include "main.h"

/**
* cleanup - Frees all dynamically allocated memory at exit
* @args: Command argument
* @command: Command entered by user
*/
void cleanup(char **args, char *command)
{
	if (command != NULL)
	{
		free(command);
		command = NULL;
	}

	if (args != NULL)
	{
		free(args);
		args = NULL;
	}
}

/**
* validate_exit_argument - Validates exit command arguments
* @arg: Exit command argument
* Return: true for valid argument, false otherwise
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
* Return: exits with 2 for invalid argument and 0 for exit
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

/**
* main - Implementation of a simple shell emulates bash
* @ac: Argument count
* @av: Argument vector.
* @envp: Environment Variables
* Return: 0 on success
*/
int main(int ac, char **av, char **envp)
{
	char *_prompt, *command = NULL, **args = NULL;
	size_t command_size = 0;
	int line_number = 0;
	bool interactive = isatty(STDIN_FILENO), should_exit = false;
	(void)ac;

	_prompt = "# ";
	while (!should_exit)
	{
		line_number++;
		if (interactive)
		{
			_puts(_prompt);
			fflush(stdout);
		}
		if (get_line(&command, &command_size, stdin) == -1)
		{
			if (interactive)
				_puts("\n");
			should_exit = true;
			break;
		}
		else if (command == NULL || command[0] == ' ' || command[0] == '\n')
			continue;
		command[_strcspn(command, "\n")] = '\0';
		args = parse_arguments(command);

		if (_strcmp(args[0], "exit") == 0)
		{
			handle_exit(args, command);
			should_exit = true;
			break;
		}
		run_command(args[0], args, envp, av, line_number);
		free(args);
		args = NULL;
	}
	if (should_exit)
		cleanup(args, command);
	return (0);
}
