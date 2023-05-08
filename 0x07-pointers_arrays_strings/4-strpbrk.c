#include "main.h"
/**
 * _strpbrk - Entry point
 * @c: input
 * @accept: input
 * Return: Always 0 (Success)
 */
char *_strpbrk(char *c, char *accept)
{
		int k;

		while (*c)
		{
			for (k = 0; accept[k]; k++)
			{
			if (*c == accept[k])
			return (c);
			}
		c++;
		}

	return ('\0');
}
