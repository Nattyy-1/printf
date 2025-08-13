#include <unistd.h>
#include <string.h>
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
	char *s;
	char temp;

	if (c == 'c')
	{
		temp = (char)va_arg(*args, int);
		write(1, &temp, 1);
		(*count)++;
	} else if (c == '%')
	{
		write(1, "%", 1);
		(*count)++;
	} else if (c == 's')
	{
		s = va_arg(*args, char *);
		if (s == NULL)
			s = "(null)";
		write(1, s, strlen(s));
		(*count) += strlen(s);
	} else if (c == 'd' || c == 'i')
	{
		di_handler(va_arg(*args, int), count);
	} else if (c == 'b')
	{
		b_handler(va_arg(*args, unsigned int), count);
	} else if (c == 'u')
	{
		u_handler(va_arg(*args, unsigned int), count);
	} else if (c == 'o')
	{
		o_handler(va_arg(*args, unsigned int), count);
	} else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		(*count) += 2;
	}
}
