#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string which is composed of 0 or more directives
 * @...: the arguments to prints that will be replaced in place of specifiers
 *
 * Return: the number of characters printed (null byte excluded)
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
			i++;
			continue;
		} else
		{
			if (format[i + 1] == '\0')
				return (-1);

			handle_specifier(format[i + 1], &args, &count);
			i += 2;
		}
	}

	va_end(args);
	return (count);
}
