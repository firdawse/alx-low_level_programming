#include "main.h"
/**
 * puts2 - function should print only one character out of two
 * starting with the first one
 * @s: input
 * Return: print
 */
void puts2(char *s)
{
	int longi = 0;
	int length = 0;
	char *y = s;
	int i;

	while (*y != '\0')
	{
		y++;
		longi++;
	}
	length = longi - 1;
	for (i = 0 ; i <= length ; i++)
	{
		if (i % 2 == 0)
	{
		_putchar(s[o]);
	}
	}
	_putchar('\n');
}

