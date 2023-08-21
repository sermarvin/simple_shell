#include "shell.h"

int _strlen(const char *s);

/**
 * _strlen - Returns length of a string
 * @s: pointer to the xters string
 * Return: The length of the xter string
 */

int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}
