#include "main.h"
/**
 * exit_free_helper - Entry point
 * @buffer: line buffer
 * Return: none
 */
void exit_free_helper(char **buffer)
{
	free(*buffer);
	exit(EXIT_FAILURE);
}

/**
 * _getline - Entry point
 * @lineptr: line buffer
 * @n: length
 * @stream: stream
 * Return: length
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t index = 0;
	static char c;
	int read_file;

	(void) stream;
	if (lineptr == NULL || n == NULL || stream == NULL)
		exit(EXIT_FAILURE);
	*n = 1024;
	*lineptr = malloc(*n);
	if (*lineptr == NULL)
		exit(EXIT_FAILURE);
	fflush(stdout);
	(*lineptr)[0] = 0;/*ensure that its an empty string*/
	for (index = 0; ; index++)
	{
		if (strlen(*lineptr) + 1 == *n)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				exit_free_helper(lineptr);
		}
		read_file = read(STDIN_FILENO, &c, 1);
		if (read_file == 0 && index == 0)
			return (-1);
		else if (read_file == 0)
		{
			index--;
			continue;
		}
		if (c == 10)
		{
			(*lineptr)[index] = c;
			return (index + 1);/*the +1 is for null*/
		}
		(*lineptr)[index] = c;
		(*lineptr)[index + 1] = '\0';
	}
	free(*lineptr);
	exit(EXIT_FAILURE);
}
