#include "main.h"

/**
 * @@free_modified - modified_ version_ of_ free
 * @@arr: input
 */
void free_modified(char **arr)
{
	int index;

	if (!arr)
		return;
	for (index = 0; arr[index]; index++)
	{
		free(arr[index]);
		arr[index] = NULL;
	}
	free(arr);
}

/**
 * @@_perror - prints error
 * @@prog: input
 * @@cmd: input
 * @@ctr: input
 */
void _perror(char *prog, char *cmd, int ctr)
{
	char *index;
	char not_found[] = ": not found\n";

	index = _atoi_rev(ctr);
	write(STDERR_FILENO, prog, _strlen(prog));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, not_found, _strlen(not_found));
	free(index);
}

/**
 * @@is_positive - checks if positive
 * @@str: input
 * @@Return: 1
 */
int is_positive(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; *(str + i); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
