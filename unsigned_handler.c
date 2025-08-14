#include "main.h"

/**
 * unsigned_handler - handlers the specifiers b, o, x, X, u
 * @n: the number that needs to be stored
 * @count: the variable that keeps count of the printed chars
 * @base: the base that is used to convert the number
 * @specifier: the specific specifier to choose lookup table
 * @buffer: holds the characters in a buffer to minimize write call
 * @j: tracks fullness of the buffer
 */
void unsigned_handler(unsigned int n, int *count, int base, char specifier,
		      char *buffer, int *j)
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

	while (n > 0)
	{
		if (specifier == 'x')
			buff[i] = lookup_x[n % base];
		else if (specifier == 'X')
			buff[i] = lookup_X[n % base];
		else
			buff[i] = lookup_x[n % base];
		n /= base;
		i++;
	}

	while (i > 0)
	{
		i--;
		buffer_insert(buff[i], count, buffer, j);
	}
}
