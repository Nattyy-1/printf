#include "main.h"

/**
 * handle_specifier -  handles how each format specifier handles
 *		       its respecitive argument
 * @c: the format specifier character
 * @args: the list of arguments that will be processed
 * @count: keeps track of the printed characters so far
 */
void handle_specifier(char c, va_list *args, int *count)
{
	if (c == 'c')
	{
		c_handler((char)va_arg(*args, int), count);
		return;
	} else if (c == '%')
	{
		percent_handler(count);
		return;
	} else if (c == 's')
	{
		s_handler(va_arg(*args, char *), count);
		return;
	} else if (c == 'd' || c == 'i')
	{
		di_handler(va_arg(*args, int), count);
		return;
	}

	if (!(unsigned_loop(c, args, count)))
	{
		write(1, "%", 1);
		write(1, &c, 1);
		(*count) += 2;
	}
}
