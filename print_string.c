#include "main.h"

/**
 * print_string - prints a given string
 * @string: the string to be printed
 * @specifier: formats the string
 * @count: keeps track of the chars printed so far
 * @buffer: keeps the chars to be printed in a buffer
 * @j: keeps track of the fullness of the buffer
 */
void print_string(char *string, char specifier, int *count, char *buffer,
		  int *j)
{
	unsigned int n;

	while (*string != '\0')
	{
		if (specifier == 's')
		{
			buffer_insert(*string, count, buffer, j);
			string++;
		} else if (specifier == 'S')
		{
			if ((*string > 0 && *string < 32) || *string >= 127)
			{
				buffer_insert('\\', count, buffer, j);
				buffer_insert('x', count, buffer, j);
				n = (unsigned int)(*string);
				if (n <= 15)
					buffer_insert('0', count, buffer, j);
				print_number_base(n, 16, 'X', count, buffer, j);
				string++;
			} else
			{
				buffer_insert(*string, count, buffer, j);
				string++;
			}
		}
	}
}
