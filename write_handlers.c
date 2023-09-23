#include "main.h"

/**
 * handle__char - prints  string
 * @a: chars
 * @buffer: buffer array
 * @flags: active flags.
 * @width: width.
 * @precision: precision
 * @size: size
 * Return: 0
 */
int handle_char(char a, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char d = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		d = '0';

	buffer[i++] = a;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = d;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_num - prints string
 * @is_negative: lists arguments
 * @index: index
 * @buffer: buffer array
 * @flags:  flags
 * @width: width.
 * @precision: precision
 * @size: size
 * Return: 0
 */
int write_number(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char d = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		d = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(index, buffer, flags, width, precision,
		length, d, extra_ch));
}
/**
 * write_num - number using a buffer
 * @index: index
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @prec: precision
 * @length: length
 * @d: pading char
 * @extra_c: another char
 * Return: 0
 */
int write_num(int index, char buffer[],
	int flags, int width, int prec,
	int length, char d, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = d = ' ';
	if (prec > 0 && prec < length)
		d = ' ';
	while (prec > length)
		buffer[--index] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = d;
		buffer[i] = '\0';
		if (flags & F_MINUS && d == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && d == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && d == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[d_start], i - d_start) +
				write(1, &buffer[index], length - (1 - d_start)));
		}
	}
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], length));
}
/**
 * write_unsigned - writes unsigned number
 * @is_negative: num is negative
 * @index: index
 * @buffer: array of chars
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: 0
 */
int write_unsigned(int is_negative, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1, i = 0;
	char d = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		d = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		d = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = d;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
		}
	}

	return (write(1, &buffer[index], length));
}

/**
 * write_pointer - write memory address
 * @buffer: arrays of chars
 * @index: index in the buffer
 * @length: length of number
 * @width: width
 * @flags: flags
 * @d: char
 * @extra_c:another char
 * @padd_start:index to start
 * Return: number of chars.
 */
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char d, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = d;
		buffer[i] = '\0';
		if (flags & F_MINUS && d == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && d == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && d == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

