#include"shell.h"

int main(int ac, char **argv)
{
    char *qury = "$ ";
    char *linequry = NULL;
    size_t n = 0; 
    ssize_t nchars_read; 
    int status;
    (void)ac;

   while(1)
   {

    printf("%s", qury);

    nchars_read = getline(&linequry, &n, stdin);

    if (nchars_read == -1 || string_compare("exit\n", linequry) == 0 )
    {
            free(linequry);
            return (-1);
    }

    linequry[nchars_read - 1] = '\0';

    if (string_compare("env", linequry) == 0)
		{
			_env();
			continue;
		}

		if (empty_line(linequry) == 1)
		{
			status = 0;
			continue;
		}

		argv = _split(linequry, " ");

            if (argv[0] != NULL)
            {
               status = executecommands(argv);
            }
            else
            {
               perror("Error");
            }
            free(argv);
    }

    return (status);
}