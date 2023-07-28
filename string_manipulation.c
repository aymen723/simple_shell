#include"main.h"

/**
 * string_concatenate - a function to concate
 * @destination: the destination buffer
 * @src: the source buffer
 *
 * Return: a pointer buffer
 */
char *string_concatenate(char *destination, char *src)
{
		int i, j;

	for (i = 0; destination[i] != '\0'; i += 1)
	{}

	for (j = 0; src[j] != '\0'; j += 1)
	{
		destination[i] = src[j];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}


/**
 * string_compare - a function
 * @string1 : the first strang
 * @string2 : the second strang
 *
 * Return: 0 if equal and negative or positive
 */
int string_compare(const char *string1, const char *string2)
{
while (*string1 && *string2)
{
if (*string1 != *string2)
{
return (*string1 - *string2);
}
string1++;
string2++;
}
return (0);
}


/**
 * string_lenght - a function that return string value
 * @c: the string memory value
 *
 * Return: the lenght of a string
 */
int string_lenght(char *c)
{
int a = 0;
while (c[a] != '\0')
{
a++;
}
return (a);
}


/**
 * string_duplication - a function for duplication
 * @chaindecharacter: the string to duplicate
 *
 * Return: pointer to the new dup
 */
char *string_duplication(const char *chaindecharacter)
{
	int length = 0;
	char *ret;

	if (chaindecharacter == NULL)
		return (NULL);
	while (*chaindecharacter++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--chaindecharacter;
	return (ret);
}
