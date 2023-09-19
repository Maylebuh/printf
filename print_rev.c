#include "main.h"
/**
 * print_rev - prints the reversed string
 * @list: list input
 * Return: string length
 */
int print_rev(va_list list)
{
	int i = 0;
	int a = 0;
	char *str = va_arg(list, char *)

	if (str == NULL)
		return (1);
	while (str[i])
	{	
		i++;
	}
	i--;
	for (i = 0; i >= 0; i--)
	{
		_putchar(str[i]);
		a++;
	}
	return (a);
}
