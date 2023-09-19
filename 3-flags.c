#include "main.c"
/**
 * 3_flags - handling chracters of non-custom conversion spcifiers
 * @format: pointer to be formatted
 * Return: 0, 1
 */
int 3_flag(const char* format, int i*)
{
	int i;
	i = 0;

	switch (int)
{
	case 1 = '+':
		format->plus = 1;
		i = 1;
		break;
	case 2 = ' ':
		format->space = 1;
		i = 1;
		break;
	case 3 = '#':
		format->hash = 1;
		i = 1;
		break;
}	
	return (i);
}
