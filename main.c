#include"shell.h"


int main(int ac, char **argv)
{
    char *qury = "(shell) $ ";
    char *linequry = NULL;
    char *linequry_copy = NULL;
    size_t n = 0; 
    ssize_t nchars_read; 
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;
    (void)ac;

while(1)
{

    printf("%s", qury);

    nchars_read = getline(&linequry, &n, stdin);

    printf("%ld\n", nchars_read);
    
    if (nchars_read == -1)
    {
            return (-1);
    }

    linequry_copy =  malloc(sizeof(char) * nchars_read);

    if (linequry_copy == NULL)
    {
        perror("tsh: memory allocation error");
        return (-1);
    }

    string_copy(linequry_copy,linequry);


    token = strtok(linequry, delim);

    while (token != NULL)
    {
        num_tokens++;
        token = strtok(NULL, delim);
    }
    num_tokens++;

    printf("%d\n", num_tokens);

    argv = malloc(sizeof(char *) * num_tokens);
    
    token = strtok(linequry_copy, delim);

    for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            string_copy(argv[i], token);
            printf("%d\n", i);
            printf("%s\n", argv[i]);
            token = strtok(NULL, delim);
        }
    argv[i] = NULL;

  
executecommands(argv);


}
    free(linequry_copy);
    free(linequry);

    return (0);
}