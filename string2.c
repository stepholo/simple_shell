#include "main.h"

/**
 * -strcpy - implementation of strcpy()
 *  @dest: string destination
 *  @src: string source
 *
 *  Return: string copy
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - functio  that duplicates a string
 * @str: string
 *
 * Return: string duplicate or NULL
 */
char *_strdup(char *str)
{
	int len, i;
	char *dup;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		dup[i] = str[i];
	}
	return (dup);
}

/**
 * _stcat - function thatconcatinates a string
 * @dest: string destination
 * @src: string source
 *
 * Return: concatinated string
 */
char *_strcat(char *dest, const char *src)
{
	int i, j;

	i = 0;
	j = _strlen(dest);

	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

/**
 * _strchr - locates a char in a string
 * @str: string
 * @ch: character to be searched
 *
 * Return: pointer to the first occurence of c
 * or NULL 
 */
char *_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (NULL);
}
