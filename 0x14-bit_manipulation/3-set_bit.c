#include "main.h"

/**
 * set_bit - sets the value of a bit to 1at a given index.
 * @num: pointer of an unsigned long int.
 * @ind: index of the bit.
 *
 * Return: 1 if it works otherwise -1.
 */
 
int set_bit(unsigned long int *num, unsigned int ind)
{
	unsigned int p;

	if (ind > 63)
		return (-1);

	p = 1 << ind
	*num = (*num | p);

	return (1);
}
