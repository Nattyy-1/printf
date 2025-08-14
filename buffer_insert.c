#include "main.h"

/**
 * buffer_insert - used to write to the buffer
 * @c: the character to be stored in the buffer
 * @count: keeps track of the stored characters
 * @buffer: buffer to store characters to minimize write call
 * @j: keeps track of the how full the buffer is
 */
void buffer_insert(char c, int *count, char *buffer, int *j)
{
	flush_full_buff(buffer, j);
	buffer[*j] = c;
	(*j)++;
	(*count)++;
}
