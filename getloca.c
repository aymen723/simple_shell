#include "main.h"

/**
 * search_path - search file between the pth
 * @cmd: cmd
 * Return: cmd pth
 */
char *search_path(char *cmd)
{
	char *pth = getenviron("pth"), *pth_cpy;
	char **pth_split;
	char *pth_concat = NULL;
	int i = 0, pth_len = 0;
	struct stat inf;

	if (stat(cmd, &inf) == 0)
		return (cmd);

	pth_cpy = malloc(string_lenght(pth) + 1);

	pth_cpy = string_copy(pth_cpy, pth);
	pth_split = _split(pth_cpy, ":");

	while (pth_split[i])
	{
		pth_len = string_lenght(pth_split[i]);

		if (pth_split[i][pth_len - 1] != '/')
			pth_concat = string_concatenate(pth_split[i], "/");

		pth_concat = string_concatenate(pth_split[i], cmd);

		if (stat(pth_concat, &inf) == 0)
			break;

		i++;
	}

	free(pth_cpy);

	if (!pth_split[i])
	{
		free(pth_split);
		return (NULL);
	}

	free(pth_split);
	return (pth_concat);
}
