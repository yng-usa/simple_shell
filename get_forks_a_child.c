#include "main.h"

/**
 * @@EXEC - forks a child process to execute
 * @@command: input
 * @@argv: input
 * @@idx: input
 * @@Return: EXEC_ command
 */
int exec(char **command, char **argv, int idx)
{
	pid_t child;
	char *fpth = NULL;
	int sts;

	fpth = _getpath(command[0]);
	if (!fpth)
	{
		_perror(argv[0], command[0], idx);
		free_modified(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(fpth, command, environ) == -1)
		{
			free(fpth), fpth = NULL;
			free_modified(command);
		}
	}
	else
	{
		waitpid(child, &sts, 0);
		free_modified(command);
		free(fpth), fpth = NULL;
	}
	return (WEXITSTATUS(sts));
}

/**
 * @@get_line - reads a line of input string
 * @@Return: string
 */
char *get_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
