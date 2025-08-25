#include "main.h"

/**
 * di_helper - helper function to handle flags for the format specifiers d & i
 * @n: the number to be checked
 * @flags: the flags being applied
 * @count: keeps track of the chars printed so far
 * @buffer: keeps the chars in a buffer
 * @j: keeps track of the fullness of the buffer
 *
 * Return: the number converted to unsigned long
 */
unsigned long di_helper(long n, format_flags_t *flags, int *count,
			char *buffer, int *j)
{
	unsigned long num;
	unsigned long u;

	if (n >= 0)
	{
		if (flags->plus)
			buffer_insert('+', count, buffer, j);
		else if (flags->space)
			buffer_insert(' ', count, buffer, j);
	} else
		buffer_insert('-', count, buffer, j);

	if (n < 0)
		u = (unsigned long)(~n) + 1UL;
	else
		u = (unsigned long)n;

	num = u;
	return (num);
}

