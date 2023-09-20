#include "main.h"

/**
 * _realloc - a function reallocates a memory block using malloc and free
 * @ptr: a pointer
 * @old_size: old size
 * @new_size: new size
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pptr, *rel;
	unsigned int i;

	if (ptr != NULL)
		pptr = ptr;
	else
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (0);
	}

	rel = malloc(new_size);
	if (rel == NULL)
		return (0);

	for (i = 0; i < old_size && i < new_size; i++)
	{
		rel[i] = pptr[i];
	}

	free(ptr);
	return (rel);
}
