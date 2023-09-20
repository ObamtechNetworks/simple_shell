#include "main.h"

/**
 * _putchar - Outputs characters and manages a buffer
 * @c: The character to be output or a control command
 * @fd: file descriptor to write to
 *
 * Return: Always returns 1, indicating a single character was processed.
 */
int _putchar(int c, int fd)
{
	static int i;
	static char buf[BUF_CAPACITY];

	if (c == BUF_CLEARING || i >= BUF_CAPACITY)
	{
		write(fd, buf, i);
		i = 0;
	}

	if (c != BUF_CLEARING)
		buf[i++] = c;

	return (1);
}
