#include"shell.h"

int main(void)
{

    char *linequry = NULL;
    char *linequry_copy = NULL;
    size_t n = 0; 
    ssize_t nchars_read; 
    int status = 0;
    char **argv;
    char *qury = "$ ";
    int num_tokens = 0;
    char *token;
    int i;

	while (1)
	{
		if (isatty(0))
			printf("%s", qury);

		nchars_read = getline(&linequry, &n, stdin);
		if (nchars_read == -1 || string_compare("exit\n", linequry) == 0)
		{
			break;
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


         linequry_copy = malloc(sizeof(char) * nchars_read);

	    string_copy(linequry_copy, linequry);

       
        token = strtok(linequry, " ");

        while (token != NULL){
            num_tokens++;
            token = strtok(NULL, " ");
        }
        num_tokens++;

        argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(linequry_copy, " ");

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * string_lenght(token));
            string_copy(argv[i], token);

            token = strtok(NULL, " ");
        }
        argv[i] = NULL;

        status = executecommands(argv);
	}

   free(argv);
   free(linequry_copy);
   free(linequry);


	return (status);
   
}