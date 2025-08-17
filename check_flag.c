#include "main.h"

/**
 * check_flag - checks the different flags that appear in the format string
 * @format: the format string that is being parsed
 * @i: tracks the character being checked currently
 * @flags: tracks the different flags that appear
 */
void check_flag(const char *format, int *i, format_flags_t *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;

	while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#'
	       || format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '+')
			flags->plus = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		else if (format[*i] == '-')
			flags->minus = 1;

		(*i)++;
	}
}
