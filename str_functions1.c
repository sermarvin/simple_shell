#include "shell.h"

int _strlen(const char *s);
int *_strcat(char *dest, const char *src);

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

/**
 * _strcat - concats two strings.
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * Return: Pointer to destination string
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}
