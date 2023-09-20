#include "main.h"
/**
 * find_file - checks the existence of a file
 * @filename: the filename to check for
 * Return: 0 if found, -1 if not found
 */
int find_file(char *filename)
{
	/*initialize the stat function*/
	struct stat exist;

	/*use if statement to check file existence*/
	if (stat(filename, &exist) == 0)
	{
		printf("Found\n");
		return (1);
	}
	perror("Not found");
	return (0);
}
/**
 * main - test find file function
 * Return: (0) success
 */
int main(int ac, char **av, char **env)
{
	if (ac < 2)
		printf("Usage: _which filename ...\n");

	int i = 1;
	while (av[i])
	{
		if (find_file(av[i]))
		{
			execve("/bin/ls", av, env);
		}
		i++;
	}
	return (0);
}
