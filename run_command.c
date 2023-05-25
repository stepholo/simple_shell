#include "main.h"

/**
* execute_command - executes the command given
* @path: path of the command
* @args: Command arguments
* @envp: environment
* @av: Argument vector
* @line_number: Command number
* Return: status
*/
int execute_command(char *path, char **args, char **envp,
		   char **av, int line_number)
{
	pid_t pid;
	int status;
	int exit_status = 0;
	(void)av;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		return (1);
	}
	else if (pid == 0)
	{
		if (path != NULL)
		{
			execve(path, args, envp);
		}

		if (_strcmp(args[0], "cd") == 0)
		{
			status = cd(args, line_number);
			exit_status = status;
			exit(status);
		}

		exit_status = 2;

	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}
	return (exit_status);
}

/**
* is_directory - function to check whether a user input is a directory
* @dir: Pointer to the directory name
* Return: true if name is of a directory otherwise false
*/
bool is_directory(const char *dir)
{
	struct stat st;

	if (stat(dir, &st) == 0)
		return (S_ISDIR(st.st_mode));

	return (false);
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

	if (_strcmp(command, "setenv") == 0)
	{
		status = setenv_builtin(args, envp);
		return (status);
	}

	else if (_strcmp(command, "unsetenv") == 0)
	{
		status = unsetenv_builtin(args, envp);
		return (status);
	}
	else if (_strcmp(command, "cd") == 0)
	{
		status = cd(args, line_number);
		return (status);
	}

	if (command != NULL && access(command, X_OK) == 0 && !is_directory(command))
		path = _strdup(command);
	else
		path = find_command_path(command);

	if (path == NULL)
	{
		error_message(av[0], line_number, args[0]);
		cleanup(args, command);
		exit(127);
	}

	status = execute_command(path, args, envp, av, line_number);
	if (path != command)
		free(path);

	return (status);
}
