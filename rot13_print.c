#include "main.h"
#include <stdlib.h>

/**
 * op_R - prints a string in rot13
 * @R: string to print
 *
 * Return: number of chars printed
 */
int op_R(va_list R)
{
	char *str;
	unsigned int i, k;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(R, char *);
	if (str == NULL)
		str = "(ahyy)";
	for (i = 0; str[i]; i++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[i])
			{
				_putchar(out[k]);
				counter++;
				break;
			}
		}
		if (!in[k])
		{
			_putchar(str[i]);
			counter++;
		}
	}
	return (counter);
}
