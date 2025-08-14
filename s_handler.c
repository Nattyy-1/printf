#include "main.h"

/**
 * s_handler - handles the format specifier s
 * @s: the string to be printed
 * @count: keeps track of te chars printed so far
 */
void s_handler(char *s, int *count)
{
	if (s == NULL)
		s = "(null)";
	write(1, s, strlen(s));
	(*count) += strlen(s);
}
