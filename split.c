#include "shell.h"

int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * token_len - locates the delimeter index marking
 * @str: the string to be searched.
 * @delim: the delimiter character
 * Return: The delimeter index marking
 */


int token_len(char *str, char *delim)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != *delim)
	{
		len++;
		index++;
	}
	return (len);
}

/**
 * count_tokens - counts the number of delimited words
 * @str: The string to be searched
 * @delim: The delimeter character
 * Return: The number of words contained within str
 */

int count_tokens(char *str, char *delim)
{
	int index, tokens = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;
	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *delim)
		{
			tokens++;
			index += token_len(str + index, delim);
		}
	}
	return (tokens);
}
