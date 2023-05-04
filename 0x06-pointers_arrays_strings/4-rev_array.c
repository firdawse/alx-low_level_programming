#include "main.h"
/**
 * reverse_array - reverse array of integers
 * @x: array
 * @n: number of elements of array
 *
 * Return: void
 */
void reverse_array(int *x, int n)
{
	int i;
	int t;

	for (i = 0; i < n--; i++)
	{
		t = x[i];
		x[i] = x[n];
		x[n] = t;
	}
}

