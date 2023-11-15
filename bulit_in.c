#include"main.h"
/**
 * bulitin - Check if command is bulitin or not
 * @com: command
 * Return: 0
 */

int bulitin(char *com)
{
	char *array[] = {
		"exit", "env", NULL
	};
	int x = 0;

	while (array[x])
	{
		if (s_cmp(com, array[x]) == 0)
			return (1);
		x++;
	}
	return (0);
}
/**
 * bulitin_com - handel bulit in command
 * @com: command
 * @av: arg
 * @stat: stat
 * @ln: length index
 */
void bulitin_com(char **com, char **av, int *stat, int ln)
{
	if (s_cmp(com[0], "exit") == 0)
		b_exit(com, av, stat, ln);
	else if (s_cmp(com[0], "env") == 0)
		b_env(com, stat);
}
/**
 * b_exit - exit shell
 * @com: command
 * @av: arg
 * @stat: status
 * @ln: length index
 */
void b_exit(char **com, char **av, int *stat, int ln)
{
	int x, val;

	val = (*stat);
	if (com[1] != NULL)
	{
		if (pos_num(com[1]))
		{
			val = _atoi(com[1]);
		}
		else
		{
			exit_err(com, av, ln);
			if (!com)
				return;
			for (x = 0; com[x]; x++)
				free(com[x]), com[x] = NULL;
			free(com), com = NULL;
			(*stat) = 2;
		}
	}
	if (!com)
		return;
	for (x = 0; com[x]; x++)
		free(com[x]), com[x] = NULL;
	free(com), com = NULL;
	exit(val);
}

/**
 * b_env - prints the current environment
 * @com: command
 * @stat: status
 */
void b_env(char **com, int *stat)
{
	int y, x;

	for (y = 0; environ[y]; y++)
	{
		write(1, environ[y], s_len(environ[y]));
		write(1, "\n", 1);
	}
	if (!com)
		return;
	for (x = 0; com[x]; x++)
		free(com[x]), com[x] = NULL;
	free(com), com = NULL;
	(*stat) = 0;
}
