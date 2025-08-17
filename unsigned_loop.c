#include "main.h"

/**
 * unsigned_loop - calls the appropriate function from the lookup table
 * @c: format specifier
 * @args: the argument list containing what is to be printed
 * @count: keeps track of the number of chars printed so far
 * @buffer: holds the character to be printed to minimize write call
 * @j: tracks the fullness of the buffer
 * @flags: keeps track of which flags are on for the specifier
 * @len_mods: holds the active length modifiers
 *
 * Return: returns a flag 1 if a matching specifier was found else 0
 */
int unsigned_loop(char c, va_list *args, int *count, char *buffer, int *j,
		  format_flags_t *flags, len_specs *len_mods)
{
	spec_handler_t u_handlers[] = {
		{unsigned_handler, 10, 'u'},
		{unsigned_handler, 8, 'o'},
		{unsigned_handler, 16, 'x'},
		{unsigned_handler, 16, 'X'},
		{unsigned_handler, 2, 'b'},
		{NULL, 0, '\0'}
	};
	int i;

	for (i = 0; u_handlers[i].func != NULL; i++)
	{
		if (u_handlers[i].spec == c)
		{
			u_handlers[i].func(args, count, u_handlers[i].base
			, u_handlers[i].spec, buffer, j, flags, len_mods);
			return (1);
		}
	}

	return (0);
}
