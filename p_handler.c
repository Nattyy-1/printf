#include "main.h"

/**
 * p_handler - handles the format specifier p which
 * @ptr: pointer holding the adress needed to be printed
 * @count: keeps track of the chars printed so far
 * @buffer: holds the chars in buffer to minimize write call
 * @j: keeps track of the fullness of the buffer
 */
void p_handler(void *ptr, int *count, char *buffer, int *j)
{
	unsigned long n;
	int i = 0;
	char s[] = "(nil)";
	char buff[32];
	char lookup[] = {"0123456789abcdef"};

	if (ptr == NULL)
	{
		while (s[i] != '\0')
			buffer_insert(s[i++], count, buffer, j);
		return;
	}

	buffer_insert('0', count, buffer, j);
	buffer_insert('x', count, buffer, j);

	n = (unsigned long) ptr;
	if (n == 0)
	{
		buffer_insert('0', count, buffer, j);
		return;
	}

	i = 0;
	while (n > 0)
	{
		buff[i++] = lookup[n % 16];
		n /= 16;
	}

	while (i > 0)
	{
		buffer_insert(buff[--i], count, buffer, j);
	}
}
