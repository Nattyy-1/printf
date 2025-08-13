#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void handle_specifier(char c, va_list *args, int *count);
void di_handler(int n, int *count);
void b_handler(unsigned int n, int *count);

#endif
