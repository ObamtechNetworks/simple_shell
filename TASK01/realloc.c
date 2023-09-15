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
	char *pptr = NULL, *rel = NULL;
	unsigned int i = 0;

	if (ptr != NULL)
		pptr = ptr;
	else
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	rel = malloc(new_size);
	if (rel == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
	{
		rel[i] = pptr[i];
	}
	free(ptr);
	return (rel);
}
