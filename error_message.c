#include "main.h"

/**
* _sprintf - handle the conversion of an integer to a string
* @str: a pointer to the buffer where the resulting string is stored
* @num: Integer to convert to a string and formated into 'str'
* Return: no return
*/
void _sprintf(char *str, int num)
{
	int i = 0, len = 0;
	char temp;

	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}

	do {
		str[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	len = i;

	for (i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}

	str[len] = '\0';
}

/**
* error_message - Prints out error message
* @avO: pointer to a string representing the name of the program
* that is running
* @line_number: integer rep the line number where the error occured
* @argO: pointer to string rep the first argument passed to the
* program when error occured
* Return: no return
*/
void error_message(char *avO, int line_number, char *argO)
{
	char *msg;
	char line_number_str[12];
	int len;

	len = _strlen(avO) + _strlen(argO) + 32;
	msg = malloc(len);
	if (msg == NULL)
	{
		perror("malloc");
		exit(1);
	}

	_strcpy(msg, avO);
	_strcat(msg, ": ");

	_sprintf(line_number_str, line_number);
	_strcat(msg, line_number_str);
	_strcat(msg, ": ");

	_strcat(msg, argO);
	_strcat(msg, ": not found\n");

	write(STDERR_FILENO, msg, _strlen(msg));
	free(msg);
}
