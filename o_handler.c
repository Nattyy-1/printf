#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * o_handler - handles the format specifier o which takes an unsigned int value
 *             and prints it's octal equivalent
 * @n: the number to be printed in octal
 * @count: the variable that tracks the number of chars printed so far
 */
void o_handler(unsigned int n, int *count)
{
        unsigned int temp;
        int tracker = 0;
        int i = 0;
        char *buff;

        if (n == 0)
        {
                write(1, "0", 1);
                (*count)++;
                return;
        }

        temp = n;
        while (temp > 0)
        {
                temp /= 8;
                tracker++;
        }

        buff = malloc(tracker * sizeof(char));
        if (!buff)
                return;

        temp = n;
        while (temp > 0)
        {
                buff[i] = (temp % 8) + '0';
                temp /= 8;
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
