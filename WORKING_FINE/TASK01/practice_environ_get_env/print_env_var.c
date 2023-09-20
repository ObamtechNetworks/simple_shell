#include <stdlib.h>
#include <stdio.h>

/**
 * main - print environment path
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	/*int i = 0;*/

	/*loop through env to print values*/
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	return (0);
}
