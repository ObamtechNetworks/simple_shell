#include "main.h"
/**
 * print_spec_s_match2 - function that prints the variadic argument specified
 * for the format specifier s
 * @arg: variadic argument
 *
 * Return: returns the number of characters printed to standard output
 */
int print_spec_s_match2(va_list arg)
{
	/* declare variables */
	unsigned int idx = 0;
	int r_value = 0;
	char *strn = NULL;

	/* initialize variable */
	strn = va_arg(arg, char *);
	r_value = 0;
	idx = 0;

	/* check for null */
	if (strn == NULL)
		strn = EMPTY_STRING;

	/* print string */
	while (strn[idx] != '\0')
	{
		r_value += _putchar(strn[idx], 2);
		idx++;
	}

	return (r_value);
}
