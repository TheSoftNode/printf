#include <unistd.h>

/**
 * function to print something
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
