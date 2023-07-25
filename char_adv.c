#include "main.h"
#include <stdlib.h>

/**
 * hex_print - prints a char's ascii value in uppercase hex
 * @c: char to print
 *
 * Return: number of chars printed (always 2)
 */
static int hex_print(char c)
{
	int counter;
	char diff = 'A' - ':';
	char d[2];

	d[0] = c / 16;
	d[1] = c % 16;
	for (counter = 0; counter < 2; counter++)
	{
		if (d[counter] >= 10)
			_putchar('0' + diff + d[counter]);
		else
			_putchar('0' + d[counter]);
	}
	return (counter);
}

/**
 * op_S - prints a string and nonprintable character ascii values
 * @S: string to print
 *
 * Return: number of chars printed
 */
int op_S(va_list S)
{
	unsigned int i;
	int counter = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			counter += 2;
			counter += hex_print(str[i]);
		}
		else
		{
			_putchar(str[i]);
			counter++;
		}
	}
	return (counter);
}

/**
 * op_r - prints astring in reverse
 * @r: string to print
 *
 * Return: number of chars printed
 */
int op_r(va_list r)
{
	char *str;
	int i, counter = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i])
		i++;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		counter++;
	}
	return (counter);
}
