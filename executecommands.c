#include"shell.h"

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