#include "main.h"

/**
 * skipDelimiters - delimiters in the given string.
 * @curr_position: Pointer to the current position in the string.
 * @delim: The delimiter characters to skip.
 * Return: A pointer to the new position after skipping delimiters.
 */
char *skipDelimiters(char *curr_position, const char *delim)
{
	/*Skip all delimiting characters with the current position*/
	while (*curr_position != '\0' && (strchr(delim, *curr_position) != NULL))
		curr_position++;
	return (curr_position);
}

/**
 * countWords - the number of words in the string.
 *
 * This function counts the number of words in the string starting from the
 * 'curr_position' until a delimiter character is encountered.
 *
 * @curr_position: Pointer to the current position in the string.
 * @delim: The delimiter characters to check for word boundaries.
 *
 * Return: 1 if a word is found, 0 otherwise.
 */
int countWords(char *curr_position, const char *delim)
{
	int found_word = 0;

	for (; *curr_position != '\0'; curr_position++)
	{
		if (strchr(delim, *curr_position) != NULL)
		{
			if (found_word)
				break;
		}
		else
			found_word = 1;
	}

	return (found_word);
}

/**
 * _strtok - a string using delimiters.
 * @str: The input string to tokenize.
 * @delim: The delimiter characters to use for tokenization.
 * Return: A pointer to the next token or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	char *store, *temp;
	static char *curr_position;
	int i,  total_len, found_word = 0;

	if (str != NULL)
		curr_position = str;

	if (curr_position == NULL || *curr_position == '\0')
		return (NULL);

	/*skip all delimiting characters with the current position*/
	curr_position = skipDelimiters(curr_position, delim);
	/*get the count of words*/
	found_word = countWords(curr_position, delim);

	/*Get the total length of the string*/
	temp = curr_position;
	for (; *temp != '\0'; temp++)
	{
		if (strchr(delim, *temp) != NULL)
		{
			if (found_word)
				break;
		}
	}
	/*get the total length of the string*/
	total_len = temp - curr_position;

	/*store the word in the heap*/
	store = malloc(sizeof(char) * total_len + 1);
	if (store == NULL)
		return (NULL);

	for (i = 0; i < total_len; i++)
		store[i] = curr_position[i];
	store[i] = '\0';

	curr_position += total_len;

	return (store);
}
