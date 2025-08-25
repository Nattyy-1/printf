#include "main.h"

/**
 * p_handler - handles the format specifier p which
 * @ptr: pointer holding the address needed to be printed
 * @count: keeps track of the chars printed so far
 * @buffer: holds the chars in buffer to minimize write call
 * @j: keeps track of the fullness of the buffer
 * @flags: keeps the active flags that apply to specifiers
 */
void p_handler(void *ptr, int *count, char *buffer, int *j,
	       format_flags_t *flags)
{
	unsigned long n;
	int i = 0, padding = 0, len = 0;
	char buff[32];
	char lookup[] = "0123456789abcdef";

	if (ptr == NULL)
	{
		print_nil(flags, &padding, count, buffer, j);
		return;
	}

	n = (unsigned long)ptr;
	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = lookup[n % 16];
			n /= 16;
		}
	}

	len = 2 + i;

	padding = flags->field_width - len;
	if (padding < 0)
		padding = 0;

	if (!flags->minus)
		insert_padding(&padding, count, buffer, j, flags, '0');

	buffer_insert('0', count, buffer, j);
	buffer_insert('x', count, buffer, j);

	while (i > 0)
		buffer_insert(buff[--i], count, buffer, j);

	if (flags->minus)
		insert_padding(&padding, count, buffer, j, flags, '0');
}
