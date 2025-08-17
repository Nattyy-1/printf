#include "main.h"

/**
 * check_length_modifier - checks for any active length modifer
 * @format: string to be checked
 * @i: the index of the character that is being checked
 * @len_mods: holds the length modifiers
 */
void check_length_modifier(const char *format, int *i, len_specs *len_mods)
{
	len_mods->l = 0;
	len_mods->h = 0;

	if (format[*i] == 'l')
	{
		len_mods->l = 1;
		(*i)++;
	} else if (format[*i] == 'h')
	{
		len_mods->h = 1;
		(*i)++;
	}
}
