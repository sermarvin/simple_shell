#include "shell.h"

int _strspn(char *s, char *accept);

/**
 * _strspn - gets the length of a prefix substring
 * @s: The string to be searched
 * @accept: The prefix to be measured
 * Return: The number of bytes in s
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}
