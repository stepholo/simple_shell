#include "main.h"

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
	(void)envp;
	(void)args;

	if (command == NULL)
		return (-1);

	/* Add any additional built-in commands here...  */

	return (-1);
}
