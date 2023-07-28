#include"shell.h"

void executecommands(char **argv)
{
      char *command = NULL;
	pid_t child_pid;

    if (argv){
        command = argv[0];


	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");

		}


       
    }
}
}