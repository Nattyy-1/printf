#include "main.h"

/**
 * percent_handler - prints the literal % character to standard output
 * @count: keeps track of the characters printed so far
 */
void percent_handler(int *count)
{
	write(1, "%", 1);
	(*count)++;
}
