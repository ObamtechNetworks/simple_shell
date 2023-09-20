#include "main.h"

/**
 * _strcmp - A function that compares two strings
 * @s1: a pointer to the first string
 * @s2: pointer to the second string for comparison
 * Description: A function that compares two strings
 * Author - Ipadeola Michael Bamidele
 * Return: 0 if same, > 0 if s1 > s2, < 0 if s2 > s1
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _strcpy - A function that copies string from src
 * including NULL terminator to buffer pointed to by dest
 * @dest: a pointer to the destination string
 * @src: a pointer to the source string to copy from
 * Description: A function that copies the string pointed
 * to by src inlcuding NULL terminator to buffer pointed
 * to by dest
 * Author - Ipadeola Michael Bamidele
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

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
	unsigned int size = 0;
	char *dup = NULL;

	/*care for when str == NULL */
	if (str == NULL)
	{
		return (NULL);
	}

	/* get size of str */
	size = _strlen(str) + 1;

	/*allocate memory to duplicate str */
	dup = malloc(size * sizeof(char));

	/*handle malloc return if charAr is NULL */
	if (dup == NULL)
	{
		return (NULL);
	}

	/*copy contents of str into new space */
	_strcpy(dup, str);
	return (dup);
}

/**
 * _strlen - A function that returns the length of a string
 * @s: a pointer to the string to evaluate its length
 * Description: A function that takes in pointer to a string
 * and then returns its length
 * Author - Ipadeola Michael Bamidele
 * Return: void
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strncpy - A function that copies a strings
 * @dest: pointer to the destination of copied string
 * @src: pointer to the source string to copy from
 * @n: the number of bytes (characters) to copy
 * Description: A function that copies a string
 * using at most n bytes from the source string and
 * then returns a pointer to the copied destination string
 * Author - Ipadeola Michael Bamidele
 * Return: Destination String
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
