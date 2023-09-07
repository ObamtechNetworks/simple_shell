#include "main.h"

/**
 * _putchar - Outputs characters and manages a buffer
 * @c: The character to be output or a control command
 *
 * This function outputs characters to the standard output and
 * manages a buffer to improve efficiency. The buffer is flushed
 * either when a control command @c equals BUF_CLEARING or when
 * the buffer reaches its capacity (BUF_CAPACITY).
 *
 * @c: The character to be output. If @c is BUF_CLEARING, the buffer
 * is flushed. Otherwise, the character is stored in the buffer.
 *
 * Return: Always returns 1, indicating a single character was processed.
 */
int _putchar(int c)
{
	int i = 0;
	char buf[BUF_CAPACITY];

	while (i < BUF_CAPACITY && c != '\0')
	{
		write(1, buf, c);
		i++
	}

	if (c != '\0')
		write(1, &c, 1);
	return (1);
}
