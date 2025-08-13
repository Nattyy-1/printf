#include "main.h"

/**
 * di_handler - handles the format specifiers d and i to print integer
 * @n: the number to be printed
 * @count: the number of characters printed to standard output
 */
void di_handler(int n, int *count)
{
	char c;
	int divisor = 1;
	int temp;
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
	}
	num = (n < 0) ? -((unsigned int)n) : n;

	temp = num;
	while (temp >= 10)
	{
		divisor *= 10;
		temp /= 10;
	}

	temp = num;
	while (divisor > 1)
	{
		c = temp / divisor + '0';
		write(1, &c, 1);
		(*count)++;
		temp %= divisor;
		divisor /= 10;
	}
}
