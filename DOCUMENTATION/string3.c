#include "main.h"

/**
 * _strncat - A function that concatenates two strings
 * @dest: pointer to the destination of concatenated strings
 * @src: pointer to the source string to concatenate
 * @n: the number of bytes (characters) to concatenate
 * Description: A function that concatenates two strings
 * using at most n bytes from the source stringand
 * then returns a pointer to the concated destination string
 * Author - Ipadeola Michael Bamidele
 * Return: Destination String
 */
char *_strncat(char *dest, char *src, int n)
{
	int length = _strlen(dest);
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[length + i] = src[i];
		i++;
	}
	dest[length + i] = '\0';

	return (dest);
}

/**
 * _strstr - A fxn that locates a substring
 * @haystack: the main string to search from
 * @needle: The substring to search from
 * Description: A function that locates a substring
 * finds the first occurene of a substring neglecting the
 * NULL terminating bytes
 * Return: A pointer to the beginning of the substring or
 * NULL when no match is found
 */

char *_strstr(char *haystack, char *needle)
{
	char *ptr_hay, *ptr_needle;

	if (!(*needle))
	{
		return (haystack);
	}

	while (*haystack)
	{
		ptr_hay = haystack;
		ptr_needle = needle;
		while (*ptr_needle && *ptr_hay == *ptr_needle)
		{
			ptr_hay++;
			ptr_needle++;
		}
		if (!(*ptr_needle))
			return (haystack);
		haystack++;
	}
	return (NULL);
}


