#include "main.h"

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

	for (ptr = str; ptr != '\0'; ptr++)
	{
		for (tmp = reject; tmp != '\0'; tmp++)
		{
			if (ptr == tmp)
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
	char *token, *ptr;

	if (str != NULL)
		*pos = str;

	ptr = *pos;
	while (*ptr != '\0' && _strchr(del, *ptr) != NULL)
	{
		ptr++;
	}
	if (*ptr == '\0')
		return (NULL);

	token = ptr;
	*pos = token + _strcspn(token, del);

	if (**pos != '\0')
	{
		**pos == '\0';
		(*pos)++;
	}

	return (token);
}
