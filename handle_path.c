#include "main.h"

/**
* build_full_path - Builds the full path of the command
* @start: where to start
* @command: command to find its path
* Return: the full path or null
*/
char *build_full_path(char *start, char *command)
{
	char *full_path;
	struct stat st;
	int full_path_size;

	full_path_size = _strlen(start) + _strlen(command) + 2;
	full_path = malloc(full_path_size);
	if (!full_path)
		return (NULL);

	_strcpy(full_path, start);
	_strcat(full_path, "/");
	_strcat(full_path, command);

	if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode))
		return (full_path);

	free(full_path);
	return (NULL);
}

/**
* find_command_path - Search for the given command in the directories
* listed in the PATH
* @command: The name of the command to search
*
* Return: The full path of the command otherwise NULL
*/
char *find_command_path(char *command)
{
	char *path_env, *path, *start, *end;
	char *result = NULL;

	path_env = _getenv("PATH", environ);
	if (!path_env)
		return (NULL);

	path = _strdup(path_env);
	if (!path)
		return (NULL);

	start = path;
	while (*start)
	{
		end = _strchr(start, ':');
		if (end)
			*end = '\0';

		result = build_full_path(start, command);
		if (result)
			break;

		if (!end)
			break;

		start = end + 1;
	}

	free(path);
	return (result);
}
