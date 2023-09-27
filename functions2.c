#include "main.h"

/**
 * _prints_reverse - prints reverse string
 * @buffer: buffer array
 * @width: width
 * @types: list arguments
 * @size: size
 * @flags: active flags
 * @precision: precision
 * Return: number of chars
 */

int _prints_reverse(va_list types, char buffer[],
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

/**
 * prints_rot13string - print string in rot13
 * @buffer: buffer array
 * @width: width
 * @types: list arguments
 * @size: size
 * @flags: active flags
 * @precision: precision
 * Return: numbers of chars
 */

int prints_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char x;
	char *str;
	unsigned int a, b;

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(flags);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				x = out[b];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			x = str[a];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

/**
 * prints_unprintable - prints ascii codes non printable chars
 * @buffer: buffer array
 * @width: width
 * @types: list arguments
 * @size: sze 
 * @flags: active flags
 * @precision: precision
 */

int prints_unprintable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int a = 0, offset = 0;

	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(precision);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[a] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[a], buffer, a + offset);
		a++;
	}
	buffer[a + offset] = '\0';
	return (write(1, buffer, a + offset));
}

/**
 * prints_pnter - prints the value
 * @buffer: buffer array
 * @width: width
 * @types: list arguments
 * @size: size
 * @flags: active flags
 * @precision: precision
 * Return: number of chars
 */

int prints_pnter(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2, length = 2, d_start = 1;
	char map_to[] = "0123456789abcdef";
	char extra_c = 0, d = ' ';
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
		d = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	i++;

	return (write_pointer(buffer, ind, length,
				width, flags, d, extra_c, d_start));
}
