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
		unsigned_handler(va_arg(*args, unsigned int), count, 2, 'b');
	} else if (c == 'u')
	{
		unsigned_handler(va_arg(*args, unsigned int), count, 10, 'u');
	} else if (c == 'o')
	{
		unsigned_handler(va_arg(*args, unsigned int), count, 8, 'o');
	} else if (c == 'x')
	{
		unsigned_handler(va_arg(*args, unsigned int), count, 16, 'x');
	} else if (c == 'X')
	{
		unsigned_handler(va_arg(*args, unsigned int), count, 16, 'X');
	} else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		(*count) += 2;
	}
}
