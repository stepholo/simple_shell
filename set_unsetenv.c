#include "main.h"

/**
* _setenv - Initialize a new enviromnment variable or modify an existng one
* @name: Name of the environment variable
* @value: Value to assign to the environment variable
* @overwrite: Flag indicating whether to overwrite an existing variable
* Return: 0 on success, -1 on error
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	int result;
	char *env_entry;
	size_t name_length, value_length;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);

	if (!overwrite && _getenv(name, environ) != NULL)
		return (0);

	name_length = _strlen(name);
	value_length = (value != NULL) ? _strlen(value) : 0;

	env_entry = (char *)malloc(name_length + value_length + 2);
	if (env_entry == NULL)
		return (-1);

	_strcpy(env_entry, name);
	env_entry[name_length] = '=';
	if (value != NULL)
		_strcpy(env_entry + name_length + 1, value);

	else
		env_entry[name_length + 1] = '\0';

	result = _putenv(env_entry);
	if (result != 0)
		free(env_entry);

	return (result);
}

/**
* _unsetenv - Remove an environment variable
* @name: Name of the environment variable to remove
* Return: 0 on success, -1 on error
*/
int _unsetenv(const char *name)
{
	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);

	return (_setenv(name, NULL, 1));
}

/**
* _putenv - Set an environment variable using a string of the form "NAME=VALUE"
* @string: The string containing the environment variable
* Return: 0 on success, -1 on error
*/
int _putenv(char *string)
{
	if (string == NULL || string[0] == '\0' ||
		_strchr(string, '=') == NULL)
	{
		return (-1);

	}

	return (_setenv(string, _strchr(string, '=') + 1, 1));
}
