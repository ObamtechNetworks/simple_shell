#include "main.h"
/**
 * main - to pass task 0 betty
 * Return: 0(success)
 */
int main(void)
{
	char *name = "Hello World";

	while (*name)
	{
		_putchar(*name);
		name++;
	}
	_putchar('\n');

	return (0);
}

