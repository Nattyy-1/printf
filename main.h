#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct spec_handler - used to build a lookup table for the different format
 *			 specifiers that use the unsigned_handler function
 * @func: function pointer
 * @base: the base number used to do the number conversion and printing
 * @spec: the specifier used to call appropriate function
 */
typedef struct spec_handler
{
	void (*func)(unsigned int, int *, int, char, char *, int *);
	int base;
	char spec;
} spec_handler_t;

int _printf(const char *format, ...);
void handle_specifier(char c, va_list *args, int *count, char *buffer, int *j);
void di_handler(int n, int *count, char *buffer, int *j);
void unsigned_handler(unsigned int n, int *count, int base, char specifier,
		      char *buffer, int *j);
void buffer_insert(char c, int *count, char *buffer, int *j);
void percent_handler(int *count, char *buffer, int *j);
void sS_handler(char *s, int *count, char *buffer, int *j, char specifier);
int unsigned_loop(char c, va_list *args, int *count, char *buffer, int *j);
void flush_full_buff(char *buffer, int *j);

#endif
