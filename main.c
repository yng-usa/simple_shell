#include "main.h"

/**
 * main-entry  point
 * @@arc:number of arguments
 * @@argv:pointer to array of arguments
 * Return: 0 success
 */

int main(int arc __attribute__((unused)), char **argv)
{
	char **cmd;
	int index = 0;
	int s;

	while (1)
	{
		char *line = get_line();

		if (!line)
		{
			if (isatty(STDERR_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		index++;

		cmd = tkn(line);
		if (!cmd)
		{
			free_modified(cmd);
			continue;
		}
		if (builtin(cmd[0]))
			builtin_handle(cmd, argv, &s, index);
		else
			s = exec(cmd, argv, index);
	}
	return (0);
}
