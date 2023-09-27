#include "main.h"
/**
 * prints_octal - prints an unsigned number
 * @buffer: buffer array
 * @width:  width
 * @types: arguments
 * @size: size
 * @flags: flags
 * @precision: precision
 * Return: printed chars
 */

int prints_octal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(width);
	n = converts_size_unsigned(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}
	if (flags & F_HASH && init_n != 0)
		buffer[i--] = '0';
	i++;
	return (writes_unsigned(0, i, buffer, flags,
				width, precision, size));
}

/**
 * _prints_hexa - prints a hexadecimal number
 * @buffer: buffer array
 * @width: width
 * @types: arguments list
 * @size: specifier size
 * @flags: calculates flags
 * @flags_ch:calculates flags
 * @precision: precision
 * @map_to: array to map
 * Return: Number of printed chars
 */

int _prints_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flags_ch, int width, int precision, int size)
{
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_n = n;
	int i = BUFF_SIZE - 2;

	UNUSED(width);
	n = convert_size_unsignd(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = map_to[n % 16];
		n /= 16;
	}
	if (flags & F_HASH && init_n != 0)
	{
		buffer[i--] = flags_ch;
		buffer[i--] = '0';
	}
	i++;
	return (writes_unsigned(0, i, buffer, flags, width, precision, size));
}

/**
 * print_not_signed - prints unsigned number
 * @buffer: buffer array
 * @width: width
 * @types: arguments list
 * @size: size
 * @flags: flags
 * @precision: precision
 * Return: printed chars
 */

int print_not_signed(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);

	n = converts_size_unsigned(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (writes_unsignd(0, i, buffer, flags, width, precision, size));
}

/**
 * prints_hexadecimal - prints unsigned
 * @buffer: buffer array
 * @width: width
 * @types: argument list
 * @size: size
 * @flags: flags
 * @precision: precision
 * Return: printed chars
 */

int prints_hexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (_prints_hexa(types, "0123456789abcdef", buffer, flags,
				'x', width, precision, size));
}

/**
 * prints_hexa_upper - prints unsigned number
 * @buffer: buffer array
 * @width: width
 * @types: arguments list
 * @size: size
 * @flags: flags
 * @precision: precision
 * Return: printed chars
 */

int prints_hexa_upper(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (_prints_hexa(types, "0123456789ABCDEF", buffer, flags,
				'X', width, precision, size));
}
