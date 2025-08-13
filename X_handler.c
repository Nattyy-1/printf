#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * X_handler - handles the format specifier X which takes an unsigned int value
 *             and prints it's hex equivalent in capital
 * @n: the number to be printed in hex
 * @count: the variable that tracks the number of chars printed so far
 */
void X_handler(unsigned int n, int *count)
{
        unsigned int temp;
        int tracker = 0;
        int i = 0;
        char *buff;
        char lookup[] = {"0123456789ABCDEF"};

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
