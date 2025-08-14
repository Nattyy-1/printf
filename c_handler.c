#include "main.h"

/**
 * c_handler - handles the format specifier
 * @c: the character to be printed
 * @count: keeps track of the printed chars so far
 */
void c_handler(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
