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
	int i = 0, j = 0;
	int count = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer_insert(format[i], &count, buffer, &j);
			i++;
			continue;
		} else
		{
			if (format[i + 1] == '\0')
			{
				write(1, buffer, j);
				va_end(args);
				return (-1);
			}

			handle_specifier(format[i + 1], &args, &count, buffer, &j);
			i += 2;
		}
	}

	write(1, buffer, j);
	va_end(args);
	return (count);
}
