#include "main.h"

/**
 * _printable - printable char
 * @d: char
 * Return: 1, 0
 */
int _printable(char d)
{
	if (d >= 32 && d < 127)
		return (1);
	return (0);
}

/**
 * append_hexa_code - hexadecimal code to buffer
 * @buffer: buffer array
 * @a: input
 * @ascii_code: ASSCI CODE.
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int a)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[a++] = '\\';
	buffer[a++] = 'x';

	buffer[a++] = map_to[ascii_code / 16];
	buffer[a] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digits - digit checker
 * @c: char
 * Return: 1, 0
 */
int is_digits(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_number - casts a number size
 * @n: number
 * @size: size indicated
 * Return: num
 */
long int convert_number(long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return (n);

	return (n);
}

/**
 * convert_size_unsigned - specified size of number
 * @n: number
 * @size: number to be casted
 * Return: value of num
 */
long int convert_size_unsigned(unsigned long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return (n);

	return (n);
}
