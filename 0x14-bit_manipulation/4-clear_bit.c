#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @num: pointer of an unsigned long int.
 * @ind: index of the bit.
 *
 * Return: 1 if it worked, -1 if it otherwise.
 */
int clear_bit(unsigned long int *num, unsigned int ind)
{
	unsigned int p;

	if (ind > 63)
		return (-1);

	p = 1 << ind;

	if (*num & p)
		*num ^= p;

	return (1);
}
