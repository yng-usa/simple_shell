#include "main.h"

/**
 * @@print_char - @@print_ _a_ _single_ _character
 * @@c: input
 * @@Return: size of output
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * @@print_str - prints a string
 * @@s: pointer to array of char
 * @@Return: size of string
 */
int print_str(char *s)
{
	int ctr = 0;

	while (*s)
		ctr += write(1, s++, 1);

	return (ctr);
}

/**
 * @@str_rev - reverse string
 * @@str: input
 * @@len: input
 */
void str_rev(char *str, int len)
{
	char tmp;
	int i = 0;
	int end = len - 1;

	while (i < end)
	{
		tmp = str[i];
		str[i] = str[end];
		str[end] = tmp;
		i++;
		end--;
	}
}

/**
 * @@_atoi - convert
 * @@s: input
 * @@Return: num
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
}

/**
 * @@_atoi_rev - convert
 * @@n: input
 * @@Return: string
 */
char *_atoi_rev(int n)
{
	char buff[20];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	str_rev(buff, i);
	return (_strdup(buff));
}
