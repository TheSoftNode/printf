#include "main.h"
#include <stdlib.h>

/**
 * op_c - prints a char
 * @c: char to print
 *
 * Return: always 1
 */
int op_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}

/**
 * op_s - prints a string
 * @s: string to print
 *
 * Return: number of chars printed
 */
int op_s(va_list s)
{
	int counter;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (counter = 0; str[counter]; counter++)
	{
		_putchar(str[counter]);
	}
	return (counter);
}
