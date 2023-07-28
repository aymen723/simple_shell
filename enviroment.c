#include"shell.h"

/**
 * _env - prints environment
*/
void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}