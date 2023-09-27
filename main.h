#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)
#define S_SHORT 1
#define S_LONG 2
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
* struct fmt - struct op
* @fmt: format
* @fn: function 
*/
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
* typedef struct fmt fmt_t - struct op
* @fmt: format.
* @fm_t: function
*/
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int _handle_print(const char *fmt, int *a,
va_list list, char buffer[], int flags, int width, int precision, int size);

int prints_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int prints_percentage(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_chars(va_list types, char buffer[],
int flags, int width, int precision, int size);

int prints_unprintable(va_list types, char buffer[],
int flags, int width, int precision, int size);


int get_flags(const char *format, int *i);
int get_width(const char *format, int *a, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *b);

int prints_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int _prints_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int prints_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int prints_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int _print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_not_signed(va_list types, char buffer[],
int flags, int width, int precision, int size);
int prints_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);


int prints_pnter(va_list types, char buffer[],
int flags, int width, int precision, int size);


int prints_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);
long int converts_number(long int n, int size);
int is_digits(char);
int appends_hexa_codes(char, char[], int a);
long int converts_size_unsigned(unsigned long int n, int size);
int _printable(char a);
int writes_number(int index, char bff[], int flags, int width, int precision,
int length, char d, char extra_c);
int handle_chars(char c, char buffer[],
int flags, int width, int precision, int size);
int write_numbs(int is_positive, int index, char buffer[],
int flags, int width, int precision, int size);
int writes_unsigned(int is_negative, int index,
char buffer[],
int flags, int width, int precision, int size);
int write_pnter(char buffer[], int index, int length,
int width, int flags, char d, char extra_c, int d_start);
int _prints_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

#endif
