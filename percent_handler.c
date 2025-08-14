#include "main.h"

/**
 * percent_handler - stores the literal % character in a buffer if not full
 * @count: keeps track of the characters printed so far
 * @buffer: hold the characters that will be printed to minimize write call
 * @j: keeps track of the fullness of the buffer
 */
void percent_handler(int *count, char *buffer, int *j)
{
	buffer_insert('%', count, buffer, j);
}
