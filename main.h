#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct format_flags - holds different flags that appear in the format str
 * @plus: checks if a + flag was detected
 * @space: checks if a space flag was detected
 * @hash: checks if a hash flag was detected
 * @zero: checks if a 0 flag was detected
 * @minus: checks if a minus flag was detected
 */
typedef struct format_flags
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;
} format_flags_t;

/**
 * struct spec_handler - used to build a lookup table for the different format
 *			 specifiers that use the unsigned_handler function
 * @func: function pointer
 * @base: the base number used to do the number conversion and printing
 * @spec: the specifier used to call appropriate function
 */
typedef struct spec_handler
{
	void (*func)(unsigned int, int *, int, char, char *, int *,
		     format_flags_t *);
	int base;
	char spec;
} spec_handler_t;

int _printf(const char *format, ...);
void handle_specifier(char c, va_list *args, int *count, char *buffer, int *j,
		      format_flags_t *flags);
void di_handler(int n, int *count, char *buffer, int *j,
		format_flags_t *flags);
void unsigned_handler(unsigned int n, int *count, int base, char specifier,
		      char *buffer, int *j, format_flags_t *flags);
void buffer_insert(char c, int *count, char *buffer, int *j);
void percent_handler(int *count, char *buffer, int *j);
void sS_handler(char *s, int *count, char *buffer, int *j, char specifier);
int unsigned_loop(char c, va_list *args, int *count, char *buffer, int *j,
		  format_flags_t *flags);
void flush_full_buff(char *buffer, int *j);
void p_handler(void *ptr, int *count, char *buffer, int *j);
void check_flag(const char *format, int *i, format_flags_t *flags);

#endif
