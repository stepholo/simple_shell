#include "main.h"
/**
 * _putchar - implementation of putchar
 * @c: char to be read
 * Return: 1(success)
 * */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/*
 * _puts - imlementation of puts char
 * @str: string to be read
 *
 * Return: string
 */
void _puts(char *str)
{
	int i = 0;
	
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\0');
}
/**
 * _strlen - function that gets the length of a string
 * @str: string to be read
 *
 * Return: length
 */
int _strlen(char *str)
{
	int len = 0;

	if (*str == NULL)
		return (0);

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
/**
 * _strcmp - function that compares two strings
 * @s1: first string
 * @s2: second sring
 *
 * Return: string difference else 0
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != NULL && *s2 != NULL) && (*s1 == *s2))
	{
		*s1++;
		*s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
	return (0);
}
/**
 * rev_str - function that reverses a string
 * @str: string to be reversed
 *
 * Return: reversed string
 */
void rev_str(char *str)
{
	int len, i;
	char *first, *last, *tmp;

	len = _strlen(str);
	first = str;
	last = str;

	for (i = 0; i < len -1; i++)
	{
		tmp = *first;
		*first = *last;
		*last = tmp;
		first++;
		last--;
	}
}
