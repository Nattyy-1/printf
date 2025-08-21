#include "main.h"

/**
 * check_field_width - checks the field width set in the format string
 * @buffer: the format string to be parsed
 * @i: keeps track of the current character in the format string
 * @flags: keeps track of the active flags and field width
 */
void check_field_width(const char *buffer, int *i, format_flags_t *flags)
{
	flags->field_width = 0;

	while (buffer[*i] >= '0' && buffer[*i] <= '9')
	{
		flags->field_width = flags->field_width * 10 + (buffer[*i] - '0');
		(*i)++;
	}
}
