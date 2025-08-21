#include "main.h"

/**
 * di_handler - handles the format specifiers d and i to store ints in a buffer
 *		and to print it once full
 * @args: the argument list where the number will be extracted from
 * @count: the number of characters printed to standard output
 * @buffer: used to holds the characters to minimize write call
 * @j: keeps track of how full the buffer is
 * @flags: keeps the active flags that apply to specifiers
 * @len_mods: holds the active length modifiers
 */
void di_handler(va_list *args, int *count, char *buffer, int *j,
		format_flags_t *flags, len_specs *len_mods)
{
	long int n;
	unsigned long num;
	int padding;

	if (len_mods->h)
		n = (short)va_arg(*args, int);
	else if (len_mods->l)
		n = va_arg(*args, long int);
	else
		n = va_arg(*args, int);
	padding = flags->field_width - num_digits(n);

	if (n < 0 || flags->plus || flags->space)
		padding -= 1;

	if (padding < 0)
		padding = 0;

	if (flags->minus)
	{
		num = di_helper(n, flags, count, buffer, j);
		print_number_base(num, 10, 'd', count, buffer, j);
		insert_padding(&padding, count, buffer, j);
	} else
	{
		insert_padding(&padding, count, buffer, j);
		num = di_helper(n, flags, count, buffer, j);
		print_number_base(num, 10, 'd', count, buffer, j);
	}
}
