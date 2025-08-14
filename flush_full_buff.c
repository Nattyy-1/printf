#include "main.h"

/**
 * flush_full_buff - checks if a given buffer is full and flushes it
 * @buffer: the buffer to be checked
 * @j: tracks fullness of the buffer
 */
void flush_full_buff(char *buffer, int *j)
{
	if (*j >= BUFFER_SIZE)
	{
		write(1, buffer, *j);
		*j = 0;
	}
}
