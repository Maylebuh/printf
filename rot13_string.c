#include "main.h"
/**
 * _rot13_string - prints the rot13'ed string
 * @list: list of argument 
 * @a: character to be printed
 * Return: printed char
 */
int _rot13_string(va_list, args)
{
	char *str = va_arg(args, char*);
	char d;
	int a, b;
	int c = 0;
	int count = 0;
	
	char in[] = {"ABCDEEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"}
	char out[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"}

	if (s == NULL)
		return (NULL);
	for (a = 0; str[i]; a++)
	{
		k = 0;
		for (b = 0; in[a]; b++)
		{
			if (in[b] == str[a])
			d = out[b]
			write(1,&d, 1);
			count++;
			k = 1;
		}
	{
	if (!k)
		d = str[a];
		write(1, &d, 1);
		count++;
	}

	}
	return (count);
}
