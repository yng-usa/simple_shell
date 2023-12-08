#include "main.h"

/**
<<<<<<< HEAD:env.c
 * _getenv - represent env
 * @name : find env variable
 * Return: value of env
=======
 * @ _getenv - represent env
 * @ name find env variable
 * Return : value of env
>>>>>>> aac1fadb97f11e76a324c3c64488d622bfa35c1f:environment.c
 */
char *_getenv(char *name)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		char *env_pair = _strdup(environ[i]);
		char *key = strtok(env_pair, "=");

		if (_strcmp(key, name) == 0)
		{
			char *val = strtok(NULL, "\n");
			char *env = _strdup(val);

			free(env_pair);
			return (env);
		}
		free(env_pair);
	}
	return (NULL);
}

/**
<<<<<<< HEAD:env.c
 * print_env - print env
 * @cmd: input
 * @sta: input
=======
 * @ _getenv - represent env
 * @ name find env variable
 * Return : value of env
>>>>>>> aac1fadb97f11e76a324c3c64488d622bfa35c1f:environment.c
 */
void print_env(char **cmd, int *sta)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_modified(cmd);
	*sta = 0;
}

/**
<<<<<<< HEAD:env.c
 * _getpath - takes pointer to array
 * @command: input
 * Return: full_path
=======
 * _GETPATH - takes_ pointer_ to_ array
 * @command: input
 * @Return: full_path
>>>>>>> aac1fadb97f11e76a324c3c64488d622bfa35c1f:environment.c
 */
char *_getpath(char *command)
{
	struct stat st;
	char *pth, *token;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
			{
				return (_strdup(command));
			}
			return (NULL);
		}
	}

	pth = _getenv("PATH");
	if (!pth)
		return (NULL);
	token = strtok(pth, ":");
	while (token)
	{
		char *fpth = malloc(strlen(token) + strlen(command) + 2);

		if (fpth)
		{
			_strcpy(fpth, token);
			_strcat(fpth, "/");
			_strcat(fpth, command);
			if (stat(fpth, &st) == 0)
			{
				free(pth);
				return (fpth);
			}
			free(fpth);
			token = strtok(NULL, ":");
		}
	}
	free(pth);
	return (NULL);
}
