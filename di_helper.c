#include "main.h"

/**
 * di_helper - helper function to handler flags for the format specifiers d & i
 * @n: the number to be checked
 * @flags: the flags being applied
 * @count: keeps track of the chars printed so far
 * @buffer: keeps the chars in a buffer
 * @j: keeps track of the fullness of the buffer
 *
 * Return: the number converted to unsigned long int
 */
unsigned long  di_helper(long int n, format_flags_t *flags, int *count,
			 char *buffer, int *j)
{
	unsigned long num;
	long long nl = (long long) n;
	unsigned long long u;

	if (n >= 0)
	{
		if (flags->plus)
		{
			buffer_insert('+', count, buffer, j);
		}
		else if (flags->space)
		{
			buffer_insert(' ', count, buffer, j);
		}
	}

	if (n < 0)
	{
		buffer_insert('-', count, buffer, j);
	}

	if (nl < 0)
		u = (unsigned long long)(-(nl + 1)) + 1ULL;
	else
		u = (unsigned long long) nl;

	num  = (unsigned long) u;
	return (num);
}
