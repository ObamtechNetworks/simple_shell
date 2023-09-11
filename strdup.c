#include "main.h"
/**
 * _strdup - creates a pointer to a newly allocated space in memory
 * @str: the string to create a copy  of it in memory
 * Description: A function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as parameter
 *
 * Return: NULL if str = NULL, else pointer to the new space
 */
char *_strdup(char *str)
{
	unsigned int size;
	char *dup;

	/*care for when str == NULL */
	if (str == NULL)
	{
		return (NULL);
	}

	/* get size of str */
	size = strlen(str) + 1;

	/*allocate memory to duplicate str */
	dup = malloc(size * sizeof(char));

	/*handle malloc return if charAr is NULL */
	if (dup == NULL)
	{
		return (NULL);
		exit(1);
	}

	/*copy contents of str into new space */
	strcpy(dup, str);
	return (dup);
}
