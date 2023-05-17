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
char *_getenv(char *name, char **envp)
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

