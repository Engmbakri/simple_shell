#include"main.h"

/**
 * tok_command - split the command
 * @line: input from user
 * Return: array
 */
char **tok_command(char *line)
{
	char *tok = NULL, *copy = NULL;
	char **com = NULL;
	int count = 0, x = 0;

	if (line == NULL)
		return (NULL);
	copy = s_dup(line);
	if (!copy)
		return (NULL);
	tok = strtok(copy, " \t\n");
	if (!tok)
	{
		free(copy);
		return (NULL);
	}
	while (tok)
	{
		count++;
		tok = strtok(NULL, " \t\n");
	}
	free(copy);
	copy = NULL;
	com = malloc(sizeof(char *) * (count + 1));
	if (com == NULL)
	{
		return (NULL);
	}
	tok = strtok(line, " \t\n");
	while (tok)
	{
		com[x] = s_dup(tok);
		tok = strtok(NULL, " \t\n");
		x++;
	}
	com[x] = NULL;

	free(line);
	return (com);
}
/**
 * read_command - read command form user
 * Return: command
 */
char *read_command(void)
{
	char *linecom = NULL;
	size_t size = 0;
	ssize_t xx;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
	xx = getline(&linecom, &size, stdin);
	if (xx == -1)
	{
		free(linecom);
		return (NULL);
	}
	if (xx > 1 && linecom[xx - 2] == '\n')
	{
		linecom[xx - 2] = '\0';
	}
	return (linecom);
}
/**
 * g_env - get environment
 * @val: input
 * Return: null
 */
char *g_env(char *val)
{
	int x = 0;
	char *copy, *gk, *va, *ev;

	if (val == NULL)
		return (NULL);
	while (environ[x] != NULL)
	{
		copy = s_dup(environ[x]);
		gk = strtok(copy, "=");

		if (gk != NULL && s_cmp(gk, val) == 0)
		{
			va = strtok(NULL, "\n");
			ev = s_dup(va);
			free(copy);
			return (ev);
		}

		free(copy);
		copy = NULL;
		x++;
	}

	return (NULL);
}
/**
 * g_pth - function gets the path
 * @command: input from user
 * Return: null
 */
char *g_pth(char *command)
{
	char *pth, *full, *tok;
	int x = 0;
	struct stat trac;

	if (command == NULL || *command == '\0')
		return (NULL);
	while (command[x])
	{
		if (command[x] == '/')
		{
			if (stat(command, &trac) == 0)
				return (s_dup(command));
			return (NULL);
		}
		x++;
	}
	pth = g_env("PATH");
	if (pth == NULL)
		return (NULL);

	tok = strtok(pth, ": ");
	while (tok != NULL)
	{
		full = malloc(s_len(tok) + s_len(command) + 2);
		if (full != NULL)
		{
			s_copy(full, tok);
			s_cat(full, "/");
			s_cat(full, command);
			if (stat(full, &trac) == 0)
			{
				free(pth);
				return (full);
			}
			free(full), full = NULL;
			tok = strtok(NULL, ":");
		}
	}
	free(pth);
	return (NULL);
}
