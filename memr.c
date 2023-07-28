#include "main.h"

/**
 * allocate - a function that allocate memmory for an array
 * @nbr: size of the arry
 * @size: the size of elemte in the array (type)
 * Return: void
 */

void *allocate(unsigned int nbr, unsigned int size)
{
	unsigned int index = 0;
	char *ptr = NULL;

	if (nbr == 0 || size == 0)
		return (NULL);

	ptr = malloc(nbr * size);

	if (ptr == NULL)
		return (NULL);

	for (; index < (nbr * size); index++)
		ptr[index] = 0;

	return (ptr);
}
