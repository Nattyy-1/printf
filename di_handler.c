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
	char c;
	int divisor = 1;
	long int n;
	unsigned long num, temp;

	if (len_mods->h)
		n = (short)va_arg(*args, int);
	else if (len_mods->l)
		n = va_arg(*args, long int);
	else
		n = va_arg(*args, int);
	if (n >= 0)
	{
		if (flags->plus)
			buffer_insert('+', count, buffer, j);
		else if (flags->space)
			buffer_insert(' ', count, buffer, j);
	}

	if (n < 0)
	{
		buffer_insert('-', count, buffer, j);
	}
	num = (n < 0) ? -((unsigned long)n) : (unsigned long)n;

	temp = num;
	while (temp >= 10)
	{
		divisor *= 10;
		temp /= 10;
	}

	temp = num;
	while (divisor >= 1)
	{
		c = temp / divisor + '0';
		buffer_insert(c, count, buffer, j);
		temp %= divisor;
		divisor /= 10;
	}
}
