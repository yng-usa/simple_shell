#include "main.h"

/**
 * exit-exit the shell
 * @ @cmd:input
 * @ @argv:input
 * @ @s:input
 * @ @index: input
 */
void exitsh(char **cmd, char **argv, int *s, int index)
{
	char *i;
	char err[] = ": exit Illegal number: ";
	int EXIT_VALUE = (*s);

	if (cmd[1])
	{
		if (atoi(cmd[1]) >= 0)
		{
			EXIT_VALUE = atoi(cmd[1]);
		}
		else
		{
			i = _atoi_rev(index);
			fputs(argv[0], stderr);
			fputs(": ", stderr);
			fputs(i, stderr);
			fputs(": ", stderr);
			fputs(cmd[1], stderr);
			fputs(err, stderr);
			fputs("\n", stderr);
			free(i);
			free_modified(cmd);
			(*s) = 2;
			return;
		}
	}
	free_modified(cmd);
	exit(EXIT_VALUE);
}
