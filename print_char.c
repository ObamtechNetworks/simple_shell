#include "main.h"
/**
 * print_spec_c_match - function prints the variadic character specified for
 * the fornat specifier c
 * @arg: variadic argument
 *
 * Return: returns the number of character print to standard output
 */
int print_spec_c_match(va_list arg)
{
	/* declare variables */
	char c;
	unsigned int r_value;

	/* initialize variables */
	c = va_arg(arg, int);
	r_value = 0;

	/* print the character specified for the specifier */
	r_value = _putchar(c, 1);

	return (r_value);
}
