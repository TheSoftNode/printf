#include "main.h"
#include <stdlib.h>

/**
 * check_format - checks if there is a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */
static int (*check_format_spec(const char *format))(va_list)
{
	unsigned int i;
	formats_t p[] = {
		{"c", op_c},
		{"s", op_s},
		{"i", op_i},
		{"d", op_d},
		{"u", op_u},
		{"b", op_b},
		{"o", op_o},
		{"x", op_x},
		{"X", op_X},
		{"p", op_p},
		{"S", op_S},
		{"r", op_r},
		{"R", op_R},
		{NULL, NULL}
	};

	for (i = 0; p[i].f != NULL; i++)
	{
		if (*(p[i].f) == *format)
		{
			break;
		}
	}
	return (p[i].func);
}

/**
 * _printf - sends formatted output to stdout.
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, counter = 0;
	va_list valist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			counter++;
		}
		if (!format[i])
			return (counter);
		f = check_format_spec(&format[i + 1]);
		if (f != NULL)
		{
			counter += f(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		counter++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(valist);
	return (counter);
}
