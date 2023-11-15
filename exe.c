#include"main.h"
/**
 * exe_command - execute command
 * @com: command
 * @av: arg
 * @ln: length index
 * Return: stat
 */
int exe_command(char **com, char **av, int ln)
{
	char *pth;
	pid_t baby;
	int status = 0, x;

	pth = g_pth(com[0]);
	if (pth == NULL)
	{
		p_err(av[0], com[0], ln);
		for (x = 0; com[x]; x++)
			free(com[x]), com[x] = NULL;
		free(com);
		com = NULL;
		return (127);
	}
	else
	{
		baby = fork();
		if (baby == 0)
		{
			ch_process(com, pth);
		}
		else
		{
			waitpid(baby, &status, 0);
			for (x = 0; com[x]; x++)
				free(com[x]), com[x] = NULL;
			free(com);
			com = NULL;
			free(pth);
			pth = NULL;
		}
	}
	return (WEXITSTATUS(status));
}
/**
 * ch_process - chiled process
 * @com: command
 * @pth: path
*/
void ch_process(char **com, char *pth)
{
	int x;

	if (execvp(pth, com) == -1)
	{
		free(pth);
		pth = NULL;
		for (x = 0; com[x]; x++)
			free(com[x]), com[x] = NULL;
		free(com);
		com = NULL;
	}
}
