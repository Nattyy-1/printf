#include "main.h"

/**
 * di_handler - handles the format specifiers d and i to store ints in a buffer
 *              and to print it once full
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
	int sign;

	if (len_mods->h)
		n = (short)va_arg(*args, int);
	else if (len_mods->l)
		n = va_arg(*args, long int);
	else
		n = va_arg(*args, int);
	sign = (n < 0 || flags->plus || flags->space) ? 1 : 0;
	padding = flags->field_width - num_digits(n) - sign;
	if (padding < 0)
		padding = 0;

	if (!flags->minus && flags->zero)
	{
		num = di_helper(n, flags, count, buffer, j);
		while (padding-- > 0)
			buffer_insert('0', count, buffer, j);
		print_number_base(num, 10, 'd', count, buffer, j);
		return;
	}

	if (flags->minus)
	{
		num = di_helper(n, flags, count, buffer, j);
		print_number_base(num, 10, 'd', count, buffer, j);
		insert_padding(&padding, count, buffer, j, flags, '1');
	}
	else
	{
		insert_padding(&padding, count, buffer, j, flags, '1');
		num = di_helper(n, flags, count, buffer, j);
		print_number_base(num, 10, 'd', count, buffer, j);
	}
}
