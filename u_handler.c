#include <unistd.h>
#include "main.h"

/**
 * u_handler - handles the format specifier u to print integer
 * @n: the number to be printed
 * @count: the number of characters printed to standard output
 */
void u_handler(unsigned int n, int *count)
{
        char c;
        int divisor = 1;
        unsigned int temp;

        temp = n;
        while (temp >= 10)
        {
                divisor *= 10;
                temp /= 10;
        }

        temp = n;
        while (divisor >= 1)
        {
                c = temp / divisor + '0';
                write(1, &c, 1);
                (*count)++;
                temp %= divisor;
                divisor /= 10;
        }
}
