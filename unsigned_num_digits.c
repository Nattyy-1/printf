#include "main.h"

/**
 * unsigned_num_digits - calculates the number of digits of an unsigned number
 * @n: the number
 * @base: the base
 *
 * Return: the number of digits
 */
int unsigned_num_digits(unsigned long n, int base)
{
	int count = 0;

	if (n == 0)
		return (1);

	while (n)
	{
		count++;
		n /= base;
	}

	return (count);
}
