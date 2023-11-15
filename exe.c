#include"main.h"
/**
 * exe_absolpth -  Function to execute a command with an absolute path
 * @com: command
 * @av: arg
 * @ln: length index
 */
void exe_absolpth(char **com, char **av, int ln)
{
	pid_t baby;
	int status;

	baby = fork();
	if (baby == 0)
	{
		execv(com[0], com);
		p_err(av[0], com[0], ln);
		exit(127);
	}
	else
	{
		waitpid(baby, &status, 0);
	}
}
/**
 * exe_relatpth - Function to execute a command with a relative path
 * @com: command
 * @av: arg
 * @ln: length index
 */
void exe_relatpth(char **com, char **av, int ln)
{
	pid_t baby;
	int status, i;
	char *pth;

	pth = g_pth(com[0]);
	if (pth != NULL)
	{
		baby = fork();
		if (baby == 0)
		{
			execvp(com[0], com);
			p_err(av[0], com[0], ln);
			free(pth);
			exit(127);
		}
		else
		{
			waitpid(baby, &status, 0);
			free(pth);
		}
	}
	else
	{
		p_err(av[0], com[0], ln);
		if (com)
		{
			for (i = 0; com[i]; i++)
				free(com[i]);
			free(com);
		}
	}
}
/**
 * exe_command - Function to execute a command
 * @com: command
 * @av: arg
 * @ln: length index
 * Return: execut command
 */
int exe_command(char **com, char **av, int ln)
{
	int status = 0, i;

	if (com[0] != NULL)
	{
		if (com[0][0] == '/')
		{
			exe_absolpth(com, av, ln);
		}
		else
		{
			exe_relatpth(com, av, ln);
		}
	}

	if (com)
	{
		for (i = 0; com[i]; i++)
			free(com[i]);
		free(com);
	}
	return (WEXITSTATUS(status));
}
