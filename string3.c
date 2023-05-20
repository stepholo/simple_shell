#include "main.h"
/**
* _strncmp - Compares two strings
* @s1: first string
* @s2: second string
* @n: number of characters to compare
* Return: an integer
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		else if (*s1 == '\0')
			return (0);

		s1++;
		s2++;
	}

	return (0);
}
/**
* _strspn - implementation of owm strspn function
* @str: string variable
* @accept: substring pointer
*
* Return: number of counts
*/
unsigned int _strspn(char *str, const char *accept)
{
	size_t i, j;
	unsigned int k;

	i = 0;
	k = 0;

	while (str[i] != '\0')
	{
		while (accept[j] != '\0')
		{
			if (str[i] == accept[j])
			{
				k++;
				break;
			}
			j++;
		}
		if (accept[j] == '\0')
			return (k);
		i++;
	}
	return (k);
}

/**
* _strcspn - implementation of strcspn()
* @str: string variable
* @reject: substring pointer
*
* Return: length of string not in reject
*/
size_t _strcspn(char *str, const char *reject)
{
	const char *ptr, *tmp;
	size_t i = 0;

	for (ptr = str; *ptr != '\0'; ptr++)
	{
		for (tmp = reject; *tmp != '\0'; tmp++)
		{
			if (*ptr == *tmp)
				return (ptr - str);
		}
		i++;
	}
	return (i);
}

/**
* _strtok - function that implements string tokenization function
* @str: string variable
* @del: deliminator
* @pos: breaking position
*
* Return: token or NULL
*/
char *_strtok(char *str, const char *del, char **pos)
{
	char *token, *start;

	if (str != NULL)
	{
		*pos = str;
	}
	start = *pos;
	while (*start != '\0' && _strchr(del, *start) != NULL)
	{
		start++;
	}
	if (*start == '\0')
	{
		return (NULL);
	}

	token = start;
	*pos = token + _strcspn(token, del);

	if (**pos != '\0')
	{
		**pos = '\0';
		(*pos)++;
	}

	return (token);
}
