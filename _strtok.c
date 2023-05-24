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
	char *d = " ";

	arguments = malloc(sizeof(char) * MAX_ARGS);
	if (arguments == NULL)
	{
		free(arguments);
	}

	token = strtok(str, d);
	while (token != NULL && counter < MAX_ARGS - 1)
	{
		arguments[counter++] = token;
		token = strtok(NULL, d);
	}
	arguments[counter] = NULL;
	return (arguments);
}
