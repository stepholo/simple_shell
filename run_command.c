#include "main.h"

/**
 * execute_command - executes the command given
 * @path: path of the command
 * @args: Command arguments
 * @envp: environment
 * Return: status
 */
int execute_command(char *path, char **args, char **envp)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		return (1);
	}
	else if (pid == 0)
	{
		execve(path, args, envp);

		if (_strcmp(args[0], "exit") == 0)
			exit_builtin(args);
		else
			perror("execve() failed");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (status);
	}
}

/**
 * run_command - Run the command given
 * @command: Input from the user
 * @args: array of arguments
 * @envp: environment variable
 * @av: The program name and arguments
 * @line_number: Keep track of the command number
 * Return: 0 on success, -1 on error
 */
int run_command(char *command, char **args, char **envp,
		char **av, int line_number)
{
	char *path = NULL;
	int status;

	if (inbuilt_command(command, args, envp, av) == 0)
		return (0);

	if (command != NULL && access(command, X_OK) == 0)
		path = _strdup(command);
	else
		path = find_command_path(command);

	if (path == NULL)
	{
		error_message(av[0], line_number, args[0]);
		return (127);
	}

	status = execute_command(path, args, envp);
	if (path != command)
		free(path);

	return (status);
}
