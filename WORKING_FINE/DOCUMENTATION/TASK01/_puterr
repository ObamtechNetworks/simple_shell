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
	static int i;
	static char buf[BUF_CAPACITY];

	if (c == BUF_CLEARING || i >= BUF_CAPACITY)
	{
		write(2, buf, i);
		i = 0;
	}

	if (c != BUF_CLEARING)
		buf[i++] = c;

	/*if (c != '\0')
	{
		write(1, &c, 1);
	}*/

	return (1);
}
