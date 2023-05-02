#include "main.h"
/**
 * puts_half - a function that prints half of a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @s: input
 * Return: half of input
 */
void puts_half(char *s)
{
	int a, n, longi;

	longi = 0;

	for (a = 0; s[a] != '\0'; a++)
		longi++;

	n = (longi / 2);

	if ((longi % 2) == 1)
		n = ((longi + 1) / 2);

	for (a = n; s[a] != '\0'; a++)
		_putchar(s[a]);
	_putchar('\n');
}

