#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

int _printf(const char *format, ...);
void handle_specifier(char c, va_list *args, int *count);
void di_handler(int n, int *count);
void unsigned_handler(unsigned int n, int *count, int base, char specifier);

#endif
