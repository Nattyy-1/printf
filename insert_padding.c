#include "main.h"

/**
 * insert_padding - inserts padding to the buffer
 * @padding: the number of padding chars to be input
 * @count: keeps track of the chars printed so far
 * @buffer: keeps chars in a buffer
 * @j: keeps track of the fullness of the buffer
 * @flags: holds the active format flags
 * @specifier: the specifier that applies for the padding
 */
void insert_padding(int *padding, int *count, char *buffer, int *j,
		    format_flags_t *flags, char specifier)
{
	char pad_char = (flags->zero && !flags->minus && specifier == '1') ? '0'
			: ' ';

	while (*padding > 0)
	{
		buffer_insert(pad_char, count, buffer, j);
		(*padding)--;
	}
}
