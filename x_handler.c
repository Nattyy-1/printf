#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * x_handler - handles the format specifier x which takes an unsigned int value
 *             and prints it's hex equivalent
 * @n: the number to be printed in hex
 * @count: the variable that tracks the number of chars printed so far
 */
void x_handler(unsigned int n, int *count)
{
        unsigned int temp;
        int tracker = 0;
        int i = 0;
        char *buff;
	char lookup[] = {"0123456789abcdef"};
        if (n == 0)
        {
                write(1, "0", 1);
                (*count)++;
                return;
        }

        temp = n;
        while (temp > 0)
        {
                temp /= 16;
                tracker++;
        }

        buff = malloc(tracker * sizeof(char));
        if (!buff)
                return;

        temp = n;
        while (temp > 0)
        {
		buff[i] = lookup[temp % 16];
		temp /= 16;
                i++;
        }

        while (i > 0)
        {
                i--;
                write(1, &buff[i], 1);
                (*count)++;
        }
        free(buff);
}
