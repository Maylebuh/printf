#include "main.h"

/**
 * get_size - calculates argument size
 * @format: formatted string
 * @b: input
 * Return: 0
 */
int get_size(const char *format, int *b)
{
	int current_index = *b + 1;
	int size = 0;

	if (format[current_index] == 'l')
		size = S_LONG;
	else if (format[current_index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*b = current_index - 1;
	else
		*b = current_index;

	return (0);
}
