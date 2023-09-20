#include "main.h"
/**
 * skip_delim - skips delimiters
 * @cur_pos: the current char position
 * @delim: the delimiter to skip
 * Return: current position
 */
char *skip_delim(char *cur_pos, const char *delim)
{
	/*Skip all delimiting characters with the current position*/
	while (*cur_pos != '\0' && (strchr(delim, *cur_pos) != NULL))
		cur_pos++;
	return (cur_pos);
}
/**
 * word_count - counts words in a given string
 * @cur_pos: the current char position
 * @delim: the delimiter to determine a word
 * Return: number of found words
 */
int word_count(char *cur_pos, const char *delim)
{
	int found_word = 0;

	for (; *cur_pos != '\0'; cur_pos++)
	{
		if (strchr(delim, *cur_pos) != NULL)
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
 * _strtok - breaks a string into array of words
 * @str: the string to break
 * @delim: the delimiter to determine where to break
 * Return: the an array of each string or array of chars
 */
char *_strtok(char *str, const char *delim)
{
	char *store = NULL;
	static char *cur_str;

	if (str != NULL)
		cur_str = str;
	/*check if current string is NULL OR LENGTH 0*/
	if (cur_str == NULL || *cur_str == '\0')
		return (NULL);/*no more tokens availabe*/

	/*skip all delimiting characters with the current position*/
	cur_str = skip_delim(cur_str, delim);

	if (*cur_str == '\0')/*if after skipping we got to end of str*/
		return (NULL);/*END OF STR*/

	store = cur_str;/*start of the current token*/
	while (*cur_str != '\0' && strchr(delim, *cur_str) == NULL)
		cur_str++;

	if (*cur_str != '\0')
	{
		*cur_str = '\0';/*add null terminate to the token*/
		cur_str++;
	}

	return (store);
}

int main(void)
{
	char str[] = "PLEASE BREAK ME";
	char *store = NULL;

	store = _strtok(str, " ");
	while (store != NULL)
	{
		printf ("%s\n", store);
		store = _strtok(NULL, " ");
	}

	return (0);

}
