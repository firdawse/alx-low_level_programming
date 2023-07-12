#include "main.h"

/**
 * get_bit - returns the bit value at a given index.
 * @num: unsigned long int input.
 * @ind: index of the bit.
 *
 * Return: value of the bit.
 */
 
int get_bit(unsigned long int num, unsigned int ind)
{
	unsigned int i;

	if (num == 0 && ind < 64)
		return (0);

	for (i = 0; i <= 63; num >>= 1, i++)
	{
		if (ind == i)
		{
			return (num & 1);
		}
	}

	return (-1);
}
