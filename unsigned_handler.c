#include "main.h"

/**
 * unsigned_handler - handlers the specifiers b, o, x, X, u
 * @n: the number that needs to be printed
 * @count: the variable that keeps count of the printed chars
 * @base: the base that is used to convert the number
 * @specifier: the specific specifier to choose lookup table
 */
void unsigned_handler(unsigned int n, int *count, int base, char specifier)
{
	int i = 0;
	char buff[32];
	char lookup_x[] = {"0123456789abcdef"};
	char lookup_X[] = {"0123456789ABCDEF"};

	if (n == 0)
	{
		write(1, "0", 1);
		(*count)++;
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
		write(1, &buff[i], 1);
		(*count)++;
	}
}
