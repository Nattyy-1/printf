#include "main.h"

/**
 * s_handler - handles the format specifier s
 * @s: the string to be printed
 * @count: keeps track of te chars printed so far
 * @buffer: used to hold characters to minimize write call
 * @j: keeps track of the size of the buffer
 */
void s_handler(char *s, int *count, char *buffer, int *j)
{
	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s != '\0')
	{
		buffer_insert(*s, count, buffer, j);
		s++;
	}
}
