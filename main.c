#include "main.h"
/**
 * main - the main function for the shell
 * @void: void
 * Return: an iteger for the status
 */
int main(void)
{
	char *linequry = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	int status = 0;
	char **argv;
	char *qury = "$ ";

	while (1)
	{
		if (isatty(0))
			printf("%s", qury);
		nchars_read = getline(&linequry, &n, stdin);
		if (nchars_read == -1 || string_compare("exit\n", linequry) == 0)
		{
			free(linequry);
			break;
		}
		linequry[nchars_read - 1] = '\0';
		if (string_compare("env", linequry) == 0)
		{
			getenvironment();
			continue;
		}
		if (testifempty(linequry) == 1)
		{
			status = 0;
			continue;
		}
		argv = _split(linequry, " ");
		argv[0] = search_path(argv[0]);
		if (argv[0] != NULL)
			status = executecommands(argv);
		else
			perror("Error");
		free(argv);
	}
	return (status);
}
