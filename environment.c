#include "main.h"

/**
* env_builtin - Prints the current environment
* @envp: Environment variable
* Return: 0
*/
int env_builtin(char **envp)
{
	char **env;

	for (env = envp; *env != NULL; env++)
	{
		_puts(*env);
		_puts("\n");
	}

	return (0);
}

/**
* _getenv - Retrive the value of an environment variable given its name
* @name: Name of the env variable to be retrieved
* @envp: Pointer to the env variable passed to the program
* Return: A pointer to the value of the env variable otherwise NULL
*/
char *_getenv(const char *name, char **envp)
{
	int i;
	size_t namelen = _strlen(name);

	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strncmp(name, envp[i], namelen) == 0 && envp[i][namelen] == '=')
		{
			return (&envp[i][namelen + 1]);
		}
	}

	return (NULL);
}

/**
* setenv_builtin - Initialize a new environment variable or
* modify an existing one
* @args: Command arguments
* @envp: Environment variable
* Return: 0 on success, -1 on error
*/
int setenv_builtin(char **args, char **envp)
{
	(void)envp;

	if (args[1] == NULL || args[2] == NULL)
	{
		_puts("Usage: setenv VARIABLE VALUE");
		_puts("\n");
		return (-1);
	}

	if (_setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}

/**
* unsetenv_builtin - Remove an environment variable
* @args: Command arguments
* @envp: Environment variable
* Return: 0 on success, -1 on error
*/
int unsetenv_builtin(char **args, char **envp)
{
	(void)envp;

	if (args[1] == NULL)
	{
		_puts("Usage: unsetenv VARIABLE");
		_puts("\n");
		return (-1);
	}

	return (0);
}
