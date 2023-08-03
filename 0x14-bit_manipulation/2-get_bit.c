#include "main.h"

/**
 * get_bit - returns the bit value at an index.
 * @num: unsigned long int input.
 * @ind: index of the bit.
 *
 * Return: value of the bit.
 */
 
int get_bit(unsigned long int num, unsigned int ind)
{
	if (ind >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((num & (1 << ind)) == 0)
		return (0);

	return (1);
}

