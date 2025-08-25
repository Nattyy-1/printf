#include "main.h"

/**
 * handle_hash_padding - handles # flag for base 8 and 16
 * @flags: pointer to flags struct
 * @n: number to print
 * @base: the base
 * @specifier: format specifier
 * @padding: pointer to padding
 * @count: pointer to total chars printed
 * @buffer: buffer to print into
 * @j: buffer fullness index
 */
void handle_hash_padding(format_flags_t *flags, unsigned long n, int base,
	char specifier, int *padding, int *count, char *buffer, int *j)
{
	if (base == 16 && flags->hash)
	{
		*padding -= (n != 0) ? 2 : 0;
		if (flags->minus)
		{
			if (n != 0)
			{
				buffer_insert('0', count, buffer, j);
				buffer_insert(specifier == 'x' ? 'x' : 'X', count, buffer, j);
			}
			print_number_base(n, base, specifier, count, buffer, j);
			insert_padding(padding, count, buffer, j, flags);
			return;
		}
		insert_padding(padding, count, buffer, j, flags);
		if (n != 0)
		{
			buffer_insert('0', count, buffer, j);
			buffer_insert(specifier == 'x' ? 'x' : 'X', count, buffer, j);
		}
		print_number_base(n, base, specifier, count, buffer, j);
		return;
	}
	if (base == 8 && flags->hash)
	{
		if (n != 0)
			(*padding)--;
		if (flags->minus)
		{
			if (n != 0)
				buffer_insert('0', count, buffer, j);
			print_number_base(n, base, specifier, count, buffer, j);
			insert_padding(padding, count, buffer, j, flags);
			return;
		}
		insert_padding(padding, count, buffer, j, flags);
		if (n != 0)
			buffer_insert('0', count, buffer, j);
		print_number_base(n, base, specifier, count, buffer, j);
	}
}
