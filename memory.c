/**This file handles various memory functions to be used in the program*/
#include "main.h"

/**
* _realloc - Implementation of realloc()
* @ptr: pointer to memory to be alocated
* @n_size: new memory block
* @o_size: old memory block
* Return: reallocated memory
*/
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	char *new_ptr, *p;
	void *memory;
	unsigned int i;

	if (n_size == o_size)
		return (ptr);
	if (ptr == NULL)
	{
		memory = malloc(n_size);
		if (memory == NULL)
			return (NULL);
		return (memory);
	}

	if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = ptr;
	memory = malloc(sizeof(*new_ptr) * n_size);
	if (memory == NULL)
	{
		free(ptr);
		return (NULL);
	}
	p = memory;
	for (i = 0; i < o_size && i < n_size; i++)
		p[i] = *new_ptr;
	free(ptr);
	return (memory);
}
