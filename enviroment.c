#include "main.h"

/**
 * getenvironment - prints environment
 * Retunr: void
 */
void getenvironment(void)
{
	int a = 0;

	while (environ[a])
	{
		printf("%s\n", environ[a]);
		a++;
	}
}

/**
 * getenviron - get env variables
 * @env: env variable
 * Return: return the env result
 */

char *getenviron(char *env)
{
	int i = 0, j;
	int status;

	while (environ[i])
	{
		status = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != env[j])
				status = 0;
		}
		if (status == 1)
			break;
		i++;
	}
	return (&environ[i][j + 1]);
}
