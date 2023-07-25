#include <unistd.h>

/**
 * _putchar - function to print something
 * @c: a character input to be printed
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
