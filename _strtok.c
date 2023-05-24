#include "shell.h"

/**
 * split_tokens - splits the string into null terminated strings
 * @str: string to be split
 *
 * Return: pointer to the NULL terminated array
*/

char **split_tokens(char *str)
{
	char *token;
	char **arguments;
	int counter = 0;
	char *d = " \t\n";

	arguments = malloc(sizeof(char *) * (MAX_ARGS + 1));
	if (arguments == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, d);
	while (token != NULL && counter < MAX_ARGS)
	{
		arguments[counter++] = token;
		token = strtok(NULL, d);
	}
	arguments[counter] = NULL;
	
	return arguments;
}
