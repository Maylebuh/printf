#include "main.h"
/**
 * get_width - printed width
 * @format: formatted string
 * @a: input
 * @list: list of arguments.
 * Return: 0
 */
int get_width(const char *format, int *a, va_list list)
{
int current_index;
int width = 0;
for (current_index = *a + 1; format[current_index] != '\0'; current_index++)
{
if (is_digit(format[current_index]))
{
width *= 10;
width += format[current_index] - '0';
}
else if (format[current_index] == '*')
{
current_index++;
width = va_arg(list, int);
break;
}
else
break;
}
*a = current_index - 1;
return (0);
}

