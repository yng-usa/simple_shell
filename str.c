#include "main.h"

/**
 * _strlen - calculate length
 * @ @s: check input
 * Return: length
 */
int _strlen(char *s)
{
	int l;

	for (l = 0; *s != '\0'; s++)
		l++;
	return (l);
}

/**
 * *_strcpy - function to copy
 *
 * @ @ dest:input
 * @ @ src:input
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	if (src[i] == '\0')
		dest[i] = src[i];
	return (dest);
}

/**
 ** _strcmp - compare two strings
 ** @ @s1: input
 ** @ @s2: input
 * Return: 1 if true, 0 if false
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			i = ((int)*s1 - 48) - ((int)*s2 - 48);
			break;
		}
		s1++;
		s2++;
	}
	return (i);
}

/**
 ** @_strdup - return a dublicated string
 ** @ @str:input
 ** Return:char
 */
char *_strdup(char *str)
{
	char *n;
	int length;
	int i;

	if (str == NULL)
		return (NULL);
	length = strlen(str) + 1;
	n = malloc(length * sizeof(char));
	if (n == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
	{
		n[i] = str[i];
	}
	return (n);
}

/**
 * _strcat - function to merge two strings
 * @ @ dest:input
 * @ @ src:input
 * Return:dest
 */
char *_strcat(char *dest, char *src)
{
	int c, c1;

	c = 0;
	while (dest[c])
		c++;
	for (c1 = 0; src[c1]; c1++)
		dest[c++] = src[c1];
	return (dest);
}
