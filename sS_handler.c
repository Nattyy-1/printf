#include "main.h"

/**
 * sS_handler - handles the format specifiers and S
 * @s: the string to be printed
 * @count: keeps track of te chars printed so far
 * @buffer: used to hold characters to minimize write call
 * @j: keeps track of the size of the buffer
 * @specifier: chooses between either s or S
 * @flags: keeps track of the active flags
 */
void sS_handler(char *s, int *count, char *buffer, int *j, char specifier,
		format_flags_t *flags)
{
	int padding;

	if (s == NULL)
	{
		s = "(null)";
	}

	padding = flags->field_width - strlen(s);
	if (padding < 0)
		padding = 0;

	if (flags->minus)
	{
		print_string(s, specifier, count, buffer, j);
		insert_padding(&padding, count, buffer, j, flags, '0');
	} else
	{
		insert_padding(&padding, count, buffer, j, flags, '0');
		print_string(s, specifier, count, buffer, j);
	}
}
