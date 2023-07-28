#include"shell.h"

int executecommands(char **argv)
{
    int id = fork(), status;
    char *command = argv[0];

	if (id == 0)
	{
		if (execve(command, argv, environ) == -1)
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