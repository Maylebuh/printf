#include "main.h"

/**
 * print_chars - prints char
 * @buffer: buffer array
 * @width: width
 * @types: arguments list
 * @size: size
 * @precision: precision
 * @flags: flags
 * Return: number of chars
 */

int print_chars(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char a = va_arg(types, int);

	return (handle_chars(a, buffer, flags, width, precision, size));
}

/**
 * prints_string - prints string
 * @buffer: buffer array
 * @width: width
 * @types: arguments list
 * @size: size
 * @precision: precision
 * @flags: flags
 * Return: number of chars
 */

int prints_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int length = 0, i;

	UNUSED(buffer);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(flags);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * prints_int - prints an integer
 * @buffer: buffer
 * @width: width
 * @types: list
 * @size: size
 * @precision: precision
 * @flags: active flags
 * Return: number of chars
 */

int prints_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int is_negative = 0;
	int i = BUFF_SIZE - 2;
	unsigned long int n;
	long int m = va_arg(types, long int);

	m = convert_number(m, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	n = (unsigned long int)m;
	if (m < 0)
	{
		n = (unsigned long int)((-1) * m);
		is_negative = 1;
	}
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer,
				flags, width, precision, size));
}

/**
 * _prints_binary - prints a number
 * @buffer: buffer array
 * @width: width
 * @types: arguments
 * @size: size
 * @precision: precision
 * @types: arguments list
 * @flags: active flags
 * Return: char printed
 */

int _prints_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int count;
	unsigned int a[32];
	unsigned int m, l, i, sum;

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);

	m = va_arg(types, unsigned int);
	l = 2147483648; /* (2 ^ 31) */
	a[0] = m / l;
	for (i = 1; i < 32; i++)
	{
		l /= 2;
		a[i] = (m / l) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * prints_percentage - prints percent sign
 * @buffer: buffer array
 * @width: width
 * @size: size
 * @types: arguments list
 * @flags: active flags
 * @precision: precision
 * Return: chars to printed
 */

int prints_percentage(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(size);
	UNUSED(types);
	UNUSED(precision);
	UNUSED(flags);

	return (write(1, "%%", 1));
}
