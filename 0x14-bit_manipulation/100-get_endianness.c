#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian 1 otherwise
 */
int get_endianness(void)
{
	unsigned int i;
	char *s;


	i = 1;
	s = (char *) &i;

	return ((int)*s);
}

