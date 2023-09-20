#include "main.h"
/**
 * print_spec_d_match - function prints the variadic argument specified for the
 * format specifier d
 * @arg: variadic argument
 *
 * Return: returns the number of characters printed to stardard output
 */
int print_spec_d_match(va_list arg)
{
	/* declare variable */
	int n, r_value;
	unsigned int num, base;

	/* initialize variables */
	n = va_arg(arg, int);
	r_value = 0;
	base = 10;

	/* account for negative number */
	if (n < 0)
	{
		num = n * -1;
		r_value += _putchar('-', 1);
	}
	else
		num = n;

	/* print the integer */
	r_value += print_number(num, base, NULL);

	return (r_value);
}
