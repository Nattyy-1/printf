#include "main.h"

/**
 * handle_specifier -  handles how each format specifier handles
 *		       its respecitive argument
 * @c: the format specifier character
 * @args: the list of arguments that will be processed
 * @count: keeps track of the printed characters so far
 * @buffer: the buffer to hold the characters being printed
 * @j: tracks the fullness of the buffer
 */
void handle_specifier(char c, va_list *args, int *count, char *buffer, int *j)
{
	if (c == 'c')
	{
		buffer_insert((char)va_arg(*args, int), count, buffer, j);
		return;
	} else if (c == '%')
	{
		percent_handler(count, buffer, j);
		return;
	} else if (c == 's')
	{
		sS_handler(va_arg(*args, char *), count, buffer, j, 's');
		return;
	} else if (c == 'S')
	{
		sS_handler(va_arg(*args, char *), count, buffer, j, 'S');
		return;
	} else if (c == 'd' || c == 'i')
	{
		di_handler(va_arg(*args, int), count, buffer, j);
		return;
	}

	if (!(unsigned_loop(c, args, count, buffer, j)))
	{
		buffer_insert('%', count, buffer, j);
		buffer_insert(c, count, buffer, j);
	}
}
