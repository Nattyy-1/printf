#include "main.h"

/**
 * unsigned_handler - handlers the specifiers b, o, x, X, u
 * @n: the number that needs to be stored
 * @count: the variable that keeps count of the printed chars
 * @base: the base that is used to convert the number
 * @specifier: the specific specifier to choose lookup table
 * @buffer: holds the characters in a buffer to minimize write call
 * @j: tracks fullness of the buffer
 * @flags: keeps track of which format flags are on for a specifier
 */
void unsigned_handler(unsigned int n, int *count, int base, char specifier,
		      char *buffer, int *j, format_flags_t *flags)
{
	int i = 0;
	char buff[32];
	char lookup_x[] = {"0123456789abcdef"};
	char lookup_X[] = {"0123456789ABCDEF"};

	if (n == 0)
	{
		buffer_insert('0', count, buffer, j);
		return;
	}

	if (flags && base == 16 &&  flags->hash)
	{
		buffer_insert('0', count, buffer, j);
		buffer_insert(specifier == 'x' ? 'x' : 'X', count, buffer, j);
	}

	while (n > 0)
	{
		if (specifier == 'x')
			buff[i++] = lookup_x[n % base];
		else if (specifier == 'X')
			buff[i++] = lookup_X[n % base];
		else
			buff[i++] = lookup_x[n % base];
		n /= base;
	}

	if (flags && base == 8 && flags->hash && buff[i - 1] != '0')
	{
		buffer_insert('0', count, buffer, j);
	}

	while (i > 0)
	{
		buffer_insert(buff[--i], count, buffer, j);
	}
}
