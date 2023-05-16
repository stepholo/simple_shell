#include "main.h"

/**
 * _prompt - prompt to be printed each in the terminal
 * Return: prompt
 */
void _prompt(void)
{
	char *p = "#cisfun$  ";
	/*print a string at the console*/
	_puts(p);
/*clear the output buffer and move the buffered data to console*/
	fflush(stdout);
}
