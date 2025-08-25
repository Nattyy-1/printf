#include "main.h"

/**
 * print_nil - prints nil if the passed pointer is null
 * @flags: keeps track of the active flags
 * @padding: the padding to be inserted
 * @count: keeps track of the chars printed so far
 * @buffer: keeps the chars to be printed in a buffer
 * @j: keeps track of the fullness of the buffer
 */
void print_nil(format_flags_t *flags, int *padding, int *count, char *buffer,
	       int *j)
{
	char s[] = "(nil)";
	int len = strlen("(nil)");
	int i = 0;

	*padding = flags->field_width - len;
	if (*padding < 0)
		*padding = 0;

	if (!flags->minus)
		insert_padding(padding, count, buffer, j, flags);

	while (s[i] != '\0')
		buffer_insert(s[i++], count, buffer, j);

	if (flags->minus)
		insert_padding(padding, count, buffer, j, flags);
}
