#include "main.h"

/**
* bring_line - updates the buffer with input
* @lineptr: buffer that stores the input
* @n: size of lineptr
* @buffer: pointer to the buffer
* @j: buffer size
*/
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if (*lineptr == NULL)
	{
		if (j > BUFSIZ)
			*n = j;

		else
			*n = BUFSIZ;

		*lineptr = buffer;
	}

	else if (*n < j)
	{
		if (j > BUFSIZ)
			*n = j;

		else
			*n = BUFSIZ;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
* get_line - Read input from stream
* @lineptr: buffer that stores the input
* @n: size of lineptr
* @stream: steam to read from
* Return: the number of bytes
*/
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer, t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(sizeof(char) * BUFSIZ);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}

		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZ)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
