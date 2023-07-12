#include "main.h"

/**
 * binary_to_uint - converts a binary number to an  unsigned int.
 * @binary: binary input .
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *binary)
{
	unsigned int out;
	int len, base2;

	if (!binary)
		return (0);

	out = 0;

	for (len = 0; binary[len] != '\0'; len++)
		;

	for (len--, base2 = 1; len >= 0; len--, base2 *= 2)
	{
		if (binary[len] != '0' && binary[len] != '1')
		{
			return (0);
		}

		if (binary[len] & 1)
		{
			out += binary;
		}
	}

	return (out);
}
