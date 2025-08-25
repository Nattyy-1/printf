#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct length_specifiers - holds the different length modifiers
 * @l: checks for the length specifier l
 * @h: checks for the length specifier h
 */
typedef struct length_specifiers
{
	int l;
	int h;
} len_specs;

/**
 * struct format_flags - holds different flags that appear in the format str
 * @plus: checks if a + flag was detected
 * @space: checks if a space flag was detected
 * @hash: checks if a hash flag was detected
 * @zero: checks if a 0 flag was detected
 * @minus: checks if a minus flag was detected
 * @field_width: keeps track of the field width required
 */
typedef struct format_flags
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;
	int field_width;
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
	void (*func)(va_list *args, int *, int, char, char *, int *,
		     format_flags_t *, len_specs *);
	int base;
	char spec;
} spec_handler_t;

int _printf(const char *format, ...);
void handle_specifier(char c, va_list *args, int *count, char *buffer, int *j,
		      format_flags_t *flags, len_specs *len_mods);
void di_handler(va_list *args, int *count, char *buffer, int *j,
		format_flags_t *flags, len_specs *len_mods);
void unsigned_handler(va_list *args, int *count, int base, char specifier,
		      char *buffer, int *j, format_flags_t *flags,
		      len_specs *len_mods);
void buffer_insert(char c, int *count, char *buffer, int *j);
void sS_handler(char *s, int *count, char *buffer, int *j, char specifier,
		format_flags_t *flags);
int unsigned_loop(char c, va_list *args, int *count, char *buffer, int *j,
		  format_flags_t *flags, len_specs *len_mods);
void flush_full_buff(char *buffer, int *j);
void p_handler(void *ptr, int *count, char *buffer, int *j,
	       format_flags_t *flags);
void check_flag(const char *format, int *i, format_flags_t *flags);
void print_number_base(unsigned long n, int base, char specifier, int *count,
		char *buffer, int *j);
void check_length_modifier(const char *format, int *i, len_specs *len_mods);
void check_field_width(const char *buffer, int *i, format_flags_t *flags);
void c_handler(char c, int *count, char *buffer, int *j,
	       format_flags_t *flags);
void insert_padding(int *padding, int *count, char *buffer, int *j,
		    format_flags_t *flags);
void print_string(char *string, char specifier, int *count, char *buffer,
		  int *j);
unsigned long di_helper(long int n, format_flags_t *flags, int *count,
			char *buffer, int *j);
int num_digits(long int n);
void print_nil(format_flags_t *flags, int *padding, int *count, char *buffer,
	       int *j);
int unsigned_num_digits(unsigned long n, int base);
void handle_hash_padding(format_flags_t *flags, unsigned long n, int base,
			 char specifier, int *padding, int *count, char *buffer,
			 int *j);
#endif
