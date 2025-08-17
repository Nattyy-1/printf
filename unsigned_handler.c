#include "main.h"

/**
 * unsigned_handler - handlers the specifiers b, o, x, X, u
 * @args: the argument list where the number is extracted from
 * @count: the variable that keeps count of the printed chars
 * @base: the base that is used to convert the number
 * @specifier: the specific specifier to choose lookup table
 * @buffer: holds the characters in a buffer to minimize write call
 * @j: tracks fullness of the buffer
 * @flags: keeps track of which format flags are on for a specifier
 * @len_mods: holds the active length specifiers
 */
void unsigned_handler(va_list *args, int *count, int base, char specifier,
		      char *buffer, int *j, format_flags_t *flags
		      , len_specs *len_mods)
{
	unsigned long int n;

	if (len_mods->h)
		n = (unsigned short)va_arg(*args, int);
	else if (len_mods->l)
		n = va_arg(*args, unsigned long);
	else
		n = va_arg(*args, unsigned int);


	if (flags && base == 16 &&  flags->hash)
	{
		buffer_insert('0', count, buffer, j);
		buffer_insert(specifier == 'x' ? 'x' : 'X', count, buffer, j);
	}


	if (flags && base == 8 && flags->hash && n != 0)
	{
		buffer_insert('0', count, buffer, j);
	}

	print_number_base(n, base, specifier, count, buffer, j);
}
