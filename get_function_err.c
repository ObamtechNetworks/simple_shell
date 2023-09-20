#include "main.h"

/**
 * find_format_handlers2- function is responsible for identifying formats
 *                        intended for use with _printf.
 *          It then calls the appropriate corresponding function based on
 *          the identified format.
 * @format: The format specifier (char, string, int, decimal, etc)
 * Return: Either NULL or the associated function pointer.
 */
int (*find_format_handlers2(const char *format))(va_list arg)
{
	format_handler2 find_func[] = {
		{"s", print_spec_s_match2},
		{"%", print_percent2},
		{NULL, NULL}
	};

	unsigned int i;

	i = 0;

	while (find_func[i].format_char)
	{
		if (format[0] == find_func[i].format_char[0])
		return (find_func[i].handler_func2);
		i++;
	}

	return (NULL);
}
