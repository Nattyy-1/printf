#include "main.h"

/**
 * print_number_base - prints a number
 * @n: the number to be printed
 * @base: the base to convert the number
 * @specifier: the type of specifier to convert the number
 * @count: tracks the number of chars printed so far
 * @buffer: holds the chars to be printed in a buffer
 * @j: tracks the fullness of the buffer
 */
void print_number_base(unsigned long n, int base, char specifier,
		int *count, char *buffer, int *j)
{
	char buff[32];
	char lookup_x[] = "0123456789abcdef";
	char lookup_X[] = "0123456789ABCDEF";
	int i = 0;

	if (n == 0)
	{
		buffer_insert('0', count, buffer, j);
		return;
	}

	while (n > 0)
	{
		if (specifier == 'X')
			buff[i++] = lookup_X[n % base];
		else
			buff[i++] = lookup_x[n % base];
		n /= base;
	}

	while (i > 0)
		buffer_insert(buff[--i], count, buffer, j);
}
