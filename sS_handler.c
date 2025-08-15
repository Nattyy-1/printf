#include "main.h"

/**
 * sS_handler - handles the format specifiers and S
 * @s: the string to be printed
 * @count: keeps track of te chars printed so far
 * @buffer: used to hold characters to minimize write call
 * @j: keeps track of the size of the buffer
 * @specifier: chooses between either s or S
 */
void sS_handler(char *s, int *count, char *buffer, int *j, char specifier)
{
	unsigned int n;

	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s != '\0')
	{
		if (specifier == 's')
		{
			buffer_insert(*s, count, buffer, j);
			s++;
		} else if (specifier == 'S')
		{
			if ((*s > 0 && *s < 32) || *s >= 127)
			{
				buffer_insert('\\', count, buffer, j);
				buffer_insert('x', count, buffer, j);
				n = (unsigned int)(*s);
				if (n <= 15)
					buffer_insert('0', count, buffer, j);
				unsigned_handler(n, count, 16, 'X', buffer, j);
				s++;
			} else
			{
				buffer_insert(*s, count, buffer, j);
				s++;	
			}
		}
	}
}
