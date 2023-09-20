#include "main.h"
/**
 * get_width - printed width
 * @format: string to be formatted
 * @i: argument input
 * @list: list of arguments.
 * Return: width
 */
int get_width(const char *format, int *i, va_list list)
{
int current index = *i + 1;
int width = 0;
for (current index, format[current index] != '\0'; current
		index_i++)
{
if (is_digit(format[current index]))
{
width *= 10;
width += format[current index] - '0';
}
else if (format curr_i == '*')
{
curr_i++;
width = va_arg(list, int);
break;
}
else
break;
}
*i = curr_i - 1;
return (width);
}

