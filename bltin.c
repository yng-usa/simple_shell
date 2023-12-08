#include "main.h"

/**
 * BUILTIN - Builtin
 * @@cmd:  input
 * Return: 0
 */
int builtin(char *cmd)
{
	char *bltn[] = { "exit", "env", "setenv", "cd", NULL };
	int i;

	for (i = 0; bltn[i]; i++)
	{
		if (_strcmp(cmd, bltn[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * * builtin_handle - builtin_handle
 * @@ cmd:input
 * @@ argv:input
 * @@ sta:input
 * @@ idx:input
 */
void builtin_handle(char **cmd, char **argv __attribute__((unused)),
		int *sta, int idx __attribute__((unused)))
{
	if (_strcmp(cmd[0], "exit") == 0)
		exitsh(cmd, argv, sta, idx);
	else if (_strcmp(cmd[0], "env") == 0)
		print_env(cmd, sta);
}
