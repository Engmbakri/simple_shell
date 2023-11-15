#include "main.h"

/**
 * main - main point
 * @ac: input
 * @av: input
 * Return: 0
 */
int main(int ac, char **av)
{
	char *lincom = NULL;
	char **com = NULL;
	int stat = 0, ln = 0;

	(void)ac;
	while (1)
	{
		lincom = read_command();
		if (lincom == NULL) /*EOF*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		ln++;
		com = tok_command(lincom);
		if (!com)
		{
			continue;
		}
		if (bulitin(com[0]))
			bulitin_com(com, av, &stat, ln);
		else
			stat = exe_command(com, av, ln);
	}

	return (0);
}
/**
 * p_err - print error
 * @val: input
 * @com: input
 * @ln: input
 */
void p_err(char *val, char *com, int ln)
{
	char *count, mss[] = ": not found\n";

	count = _itoa(ln);
	write(STDERR_FILENO, val, s_len(val));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, count, s_len(count));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, com, s_len(com));
	write(STDERR_FILENO, mss, s_len(mss));
	free(count);
}
/**
 * exit_err - print the format of exit error
 * @com: command
 * @av: arg
 * @ln: length index
*/
void exit_err(char **com, char **av, int ln)
{
	char *count, mss[] = ": exit: Illegal number: ";

	count = _itoa(ln);
	write(STDERR_FILENO, av[0], s_len(av[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, count, s_len(count));
	write(STDERR_FILENO, mss, s_len(mss));
	write(STDERR_FILENO, com[1], s_len(com[1]));
	write(STDERR_FILENO, "\n", 1);
	free(count);
}
/**
 * _itoa -  convert to string
 *
 * @num: input
 *
 * Return: convert integer from string
 */
char *_itoa(int num)
{
	char list[35], tmp;
	int x = 0, fir = 0, en;
	char *resul;

	if (num == 0)
		list[x++] = '0';
	else
	{
		while (num > 0)
		{
			list[x++] = (num % 10) + 48;
			num = num / 10;
		}
	}
	list[x] = '\0';

	en = x - 1;
	while (fir < en)
	{
		tmp = list[fir];
		list[fir] = list[en];
		list[en] = tmp;
		fir++;
		en--;
	}
	resul = s_dup(list);
	if (resul == NULL)
		exit(EXIT_FAILURE);
	return (resul);
}
/**
 * _atoi - convert to int
 * @str: string
 * Return: convert num
*/
int _atoi(char *str)
{
	int x;
	int number = 0;

	for (x = 0; str[x]; x++)
	{
		number = number * 10;
		number += (str[x] - '0');
	}
	return (number);
}
