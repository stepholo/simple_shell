#inlcude "main.h"

/**
* parse_arguments - Function to parse command line arguments
* @command: command line input string
* Return: Array of strings representing the arguments, or NULL on failure
*/
char **parse_arguments(char *command)
{
	const char *delim = " \t\r\n\a";
	char **args;
	char *token, *end;
	int i = 0;

	while (*command != '\0' && isspace(*command))
	{
		command++;
	}

	end = command + _strlen(command) - 1;
	while (end > command && isspace(*end))
	{
		*end-- = '\0';
	}

	args = malloc(MAX_ARGUMENTS * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc() failed");
		return (NULL);
	}

	token = _strtok(command, delim, &command);
	while (token != NULL && i < MAX_ARGUMENTS - 1)
	{
		args[i++] = token;
		token = _strtok(NULL, delin, &command);
	}

	args[i] = NULL;
	return (args);
}
