#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @binary: binary string.
 *
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *binary)
{
	unsigned int decimal;
	int len, base_two;

	if (!binary)
		return (0);

	decimal = 0;

	for (len = 0; binary[len] != '\0'; len++)
		;

	for (len--, base_two = 1; len >= 0; len--, base_two *= 2)
	{
		if (binary[len] != '0' && binary[len] != '1')
		{
			return (0);
		}

		if (binary[len] & 1)
		{
			decimal += base_two;
		}
	}

	return (decimal);
}
