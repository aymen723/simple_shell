#include"shell.h"

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

    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return ret;
}