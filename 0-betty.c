#include "main.h"
/**
 * print_char - prints a char to stdout
 * @c: the character to print
 * Return: 0(success)
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (0);
}
