#include "main.h"

/**
 * c_handler - handles the format specifier c
 * @c: the character to be printed
 * @count: keeps track of the chars printed so far
 * @buffer: holds the chars in a buffer
 * @j: keeps track of the fullness of the buffer
 * @flags: keeps track of the active flags
 */
void c_handler(char c, int *count, char *buffer, int *j, format_flags_t *flags)
{
	int padding = flags->field_width - 1;

	if (padding <  0)
		padding = 0;

	if (flags->minus)
	{
		buffer_insert(c, count, buffer, j);
		insert_padding(&padding, count, buffer, j);
	} else
	{
		insert_padding(&padding, count, buffer, j);
		buffer_insert(c, count, buffer, j);
	}
}
