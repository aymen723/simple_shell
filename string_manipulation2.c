#include"main.h"
/**
 * testifempty - checks if there is alot of spaces
 * @command: space
 * Return: 0 wla 1
 */

int testifempty(char *command)
{
int a;
for (a = 0; command[a] != '\0'; a++)
{
if (command[a] != ' ')
{
return (0);
}
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
	split_str = (char **)allocate(100, sizeof(char *));

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

/**
 * string_copy - a funtion to get a copie of a string
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
return (ret);
}
