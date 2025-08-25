#include "main.h"

/**
 * num_digits - counts the number of digits in a given number
 * @n: the number to be counted
 *
 * Return: the number of digits in the number
 */
int num_digits(long n)
{
	unsigned long u;
	int count = 0;

	if (n == 0)
		return (1);

	/* Safe magnitude conversion without signed overflow */
	if (n < 0)
		u = (unsigned long)(~n) + 1UL;
	else
		u = (unsigned long)n;

	while (u > 0)
	{
		u /= 10;
		count++;
	}

	return (count);
}
