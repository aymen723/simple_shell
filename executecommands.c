#include "main.h"

/**
 * executecommands - the function to execute the commands
 * @argv: the array that hold the user command
 * Return: and integer
 */
int executecommands(char **argv)
{
	int id = fork(), status;

	if (id == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	return (status);
}
