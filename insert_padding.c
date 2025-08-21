#include "main.h"

/**
 * insert_padding - inserts padding to the buffer
 * @padding: the number of padding chars to be input
 * @count: keeps track of the chars printed so far
 * @buffer: keeps chars in a buffer
 * @j: keeps track of the fullness of the buffer
 */
void insert_padding(int *padding, int *count, char *buffer, int *j)
{
	while (*padding > 0)
	{
		buffer_insert(' ', count, buffer, j);
		(*padding)--;
	}
}
