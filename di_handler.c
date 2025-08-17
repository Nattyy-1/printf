#include "main.h"

/**
 * di_handler - handles the format specifiers d and i to store ints in a buffer
 *		and to print it once full
 * @n: the number to be stored
 * @count: the number of characters printed to standard output
 * @buffer: used to holds the characters to minimize write call
 * @j: keeps track of how full the buffer is
 * @flags: keeps the active flags that apply to specifiers
 */
void di_handler(int n, int *count, char *buffer, int *j, format_flags_t *flags)
{
	char c;
	int divisor = 1;
	unsigned int temp;
	unsigned int num;

	if (n >= 0)
	{
		if (flags->plus)
			buffer_insert('+', count, buffer, j);
		else if (flags->space)
			buffer_insert(' ', count, buffer, j);
	}

	if (n < 0)
	{
		buffer_insert('-', count, buffer, j);
	}
	num = (n < 0) ? -((unsigned int)n) : (unsigned int)n;

	temp = num;
	while (temp >= 10)
	{
		divisor *= 10;
		temp /= 10;
	}

	temp = num;
	while (divisor >= 1)
	{
		c = temp / divisor + '0';
		buffer_insert(c, count, buffer, j);
		temp %= divisor;
		divisor /= 10;
	}
}
