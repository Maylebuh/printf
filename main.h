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

int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);

int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);


int get_flags(const char *format, int *i);
int get_width(const char *format, int *a, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *b);

int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);


int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);


int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);
long int convert_number(long int num, int size);
int is_digits(char);
int append_hexa_code(char, char[], int a);
long int convert_size_unsgnd(unsigned long int num, int size);
int _printable(char a);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char d, char extra_c);
int handle_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_num(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_unsigned(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

#endif
