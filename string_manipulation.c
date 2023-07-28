#include"shell.h"

/**
 * string_concatenate - a function to concate
 * @destination: the destination buffer
 * @src: the source buffer
 *
 * Return: a pointer buffer
 */
char *string_concatenate(char *destination, char *src)
{
	int a, b;

	for (a = 0; destination[a] != '\0'; a += 1)
	{}

	for (b = 0; src[b] != '\0'; b += 1)
	{
		destination[a] = src[b];
		a++;
	}
	destination[a] = '\0';
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
            return (*string1 - *string2);

        string1++;
        string2++;
    }

    return 0;
}


/**
 * _strlen - a function that return string value
 * @c: the string memory value
 *
 * Return: the lenght of a string
 */

int string_lenght(char *c)
{
   int i = 0;

	while (c[i] != '\0')
		i++;

	return (i);
}

/**
 * _strdup - a function for duplication
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

/**
 * _strcpy - a funtion to get a copie of a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to the new string
 */
char *string_copy(char *dest, const char *src)
{
    char *ret = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return ret;
}



/**
 * empty_line - checks if exists a empty line
 * @buff: line
 * Return: 0 or 1 (int)
 */

int empty_line(char *command)
{
	int i;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] != ' ')
			return (0);
	}
	return (1);
}



/**
 * _split - split string
 * @str: string
 * @sep: separator
 * Return: divided path
 */

char **_split(char *str, char *sep)
{
	char *aux, **split_str;
	int i = 0;

	aux = strtok(str, sep);
	split_str = (char **)_calloc(100, sizeof(char *));

	if (!split_str)
	{
		free(split_str);
		return (NULL);
	}

	while (aux)
	{
		split_str[i] = aux;
		aux = strtok(NULL, sep);
		i++;
	}
	return (split_str);
}