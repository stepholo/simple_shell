#inlcude "main.h"

/**
* inbuilt_command - Function that handles shell built-in commands
* @command: Input from the user to be executed
* @args: command arrays
* @envp: Environment variables
* @av: the program name and argument
* Return: 0 on success, -1 on error
*/
int inbuilt_command(char *command, char **args, char **envp, char **av)
{
	(void)av;

	if (command == NULL)
		return (-1);

	if (_strcmp(command, "exit") == 0)
		return (exit_builtin(args));

	if (_strcmp(command, "env") == 0)
		return (env_builtin(envp));

	if (_strcmp(command, "cd") == 0)
		return (cd(args));

	/* Add any additional built-in commands here...  */

	return (-1);
}
