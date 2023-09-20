#include "main.h"

/**
 * main - print environment variable using global environ
 * Return: 0
 */
int main(int ac, char **av , char **env)
{
	printf("Environment variables");

	while (*environ)
	{
		printf("%s\n", *environ);
		environ++;
	}

	printf("env from main: %p\n", &env);/*specific to main function in the stack*/
	printf("env from global: %p\n", &environ);/*found in the data section of program*/

	return (0);
}
