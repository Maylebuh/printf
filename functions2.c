#include "main.h"

/************************* PRINT REVERSE *************************/

/**
 * print_reverse - Prints reverse string
 * @buffer: Buffer array to handle print
 * @width: get width
 * @types: list of arguments
 * @size: Size specifier
 * @flags: Calculates active flags
 * @precision: Precision specification
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, count = 0;
	char *str;

	UNUSED(buffer);
	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);

	str = va_arg(types, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		for (i = i - 1; i >= 0; i--)
		{
			char z = str[i];

			write(1, &z, 1);
			count++;
		}
	return (count);
}

/************************* PRINT A STRING IN ROT13 *************************/

/**
 * print_rot13string - Print a string in rot13
 * @buffer: Buffer array to handle print
 * @width: get width
 * @types: list of arguments
 * @size: Size specifier
 * @flags: Calculates active flags
 * @precision: Precision specification
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char x;
	char *str;
	unsigned int i, j;

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(flags);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

/************************* PRINT NON PRINTABLE *************************/

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @buffer: Buffer array to handle print
 * @width: get width
 * @types: list of arguments
 * @size: Size specifier
 * @flags: Calculates active flags
 * @precision: Precision specification
 */

int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int i = 0, offset = 0;

	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(precision);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}

/****************** PRINT POINTER ******************/

/**
 * print_pointer - Prints the value of a pointer variable
 * @buffer: Buffer array to handle print
 * @width: get width
 * @types: list of arguments
 * @size: Size specifier
 * @flags: Calculates active flags
 * @precision: Precision specification
 * Return: Number of chars printed
 */

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	char map_to[] = "0123456789abcdef";
	char extra_c = 0, padd = ' ';
	void *addrs = va_arg(types, void *);
	unsigned long num_addrs;

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
				width, flags, padd, extra_c, padd_start));
}
