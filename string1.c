#include "main.h"

/**
 * _memcpy - A function that copies a memory area
 * @dest: The destination memory location to copy to
 * @src: The memory source to copy from
 * @n: The most n bytes of characters to copy
 * Description: A function that copies a memory area
 * from source to destination based on given n bytes to copy
 * Return: a pointer to the memory area *s
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
 * _memset - A function that fills memory with a constant byte
 * @s: The destination memory location to fill
 * @b: The constant character to fill the memory
 * @n: The most n bytes of characters to fill in
 * Description: A function that fills memory with a constant byte
 * Return: a pointer to the memory area *s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}

/**
 * _puts - A function that prints a string followed by a new line
 * @str: a pointer to the string of characters to print
 * Description: A function that prints a string
 * followed by a new line to stdout
 * Author - Ipadeola Michael Bamidele
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	_putchar(10);
}

/**
 * _strcat - A function that concatenates two strings
 * @dest: pointer to the destination of concatenated strings
 * @src: pointer to the source string to concatenate
 * Description: A function that concatenates two strings and
 * then returns a pointer to the concated destination string
 * Author - Ipadeola Michael Bamidele
 * Return: Destination String
 */
char *_strcat(char *dest, char *src)
{
	int length = _strlen(dest);
	int i = 0;

	while (src[i] != '\0')
	{
		dest[length + i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _strchr - A function that locates a character in a string
 * @s: The string to search from
 * @c: The character to search for
 * Description: A function that searches for the first occurence
 * of a character in a string and returns a pointer to the FIRST
 * occurrence of the character
 * Return: a pointer to the first occurence of the character
 */

char *_strchr(char *s, char c)
{
	if (c == '\0')
	{
		while (*s != '\0')
			s++;
		return (s); /* returns a pointer to the null character of s*/
	}

	while (*s != '\0')
	{
		if (*s == c) /* if character is found */
		{
			return (s); /**
					  * returns a pointer to the
					  * address of the found
					  * character
					  * (hence FIRST occurence)
					  * loop stops
					  */
		}
		s++; /** updates counter, move to next character
		       * checks condition again
		       * (if true) => performs another check on string
		       */
	}
	return (NULL); /* returns NULL if nothing was found eventually */
}
