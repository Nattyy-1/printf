#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * b_handler - handles the format specifier b which takes an int value
 *	       and prints it's binary equivalent
 * @n: the number to be printed in binary
 * @count: the variable that tracks the number of chars printed so far
 */
void b_handler(unsigned int n, int *count)
{
	unsigned int temp;
	int tracker = 0;
	int i = 0;
	char *buff;

	temp = n;
	while (temp > 0)
	{
		temp /= 2;
		tracker++;
	}

	buff = malloc(tracker * sizeof(char));
	if (!buff)
		return;

	temp = n;
	while (temp > 0)
	{
		buff[i] = (temp % 2) + '0';
		temp /= 2;
		i++;
	}

	while (i > 0)
	{
		i--;
		write(1, &buff[i], 1);
		(*count)++;
	}
	free(buff);
}
