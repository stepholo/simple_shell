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
* main - Implementation of a simple shell
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
