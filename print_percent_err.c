#include "main.h"

/**
 * print_percent2 - Prints a percent symbol
 * @arg: A va_list argument (unused)
 *
 * Description - This function prints a single percent symbol ("%") to the
 *		output.The argument @arg is not used in this implementation.
 *
 * Return: The number of bytes printed (always 1)
 */
int print_percent2(va_list arg)
{
	(void)arg;
	return (_putchar('%', 2));
}
