#include "main.h"

/**
 * execute_func2 - finds the format func
 * @s: the format string
 * @arg: argument pointer
 *
 * Return: the number of bytes printed
 */
int execute_func2(char *s, va_list arg)
{
	int (*print_func)(va_list) = find_format_handlers(s);

	if (print_func)
		return (print_func(arg));

	return (0);
}

/**
 * produce_range2 - outputs characters within a specified address range
 * @start: start address
 * @stop: stop address
 *
 * Return: number bytes emitted
 */
int produce_range2(char *start, char *stop)
{
	int r_value = 0;

	for (; start <= stop; start++)
		r_value += _putchar(*start, 2);

	return (r_value);
}

/**
  * _fprintf - function that generatess output in accordance to a given format
  * @format: format (char, string, int, decimal)
  * Return: size the output text;
  */
int _fprintf(const char *format, ...)
{
	unsigned int r_value = 0;
	char *ptr = (char *)format, *specifier_start;
	va_list args;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);

	for (; *ptr; ptr++)
	{
		if (*ptr != '%')
		{
			r_value += _putchar(*ptr, 2);
			continue;
		}
		specifier_start = ptr;
		ptr++;
		if (find_format_handlers2(ptr))
			r_value += execute_func2(ptr, args);
		else
			r_value += produce_range2(specifier_start, ptr);
	}
	_putchar(BUF_CLEARING, 2);
	va_end(args);

	return (r_value);
}
