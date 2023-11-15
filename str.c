#include"main.h"
/**
 * s_len - function deretmines the length of string
 *
 * @str: string
 *
 * Return: length
 */
int s_len(char *str)
{
	int x = 0;

	if (str == NULL)
		return (0);
	while (*str++)
		x++;
	return (x);
}
/**
 * s_cmp - compar string
 *
 * @str1: string 1
 * @str2: string2
 *
 * Return: 0
 */
int s_cmp(char *str1, char *str2)
{
	int s = 0;

	while (str1[s] != '\0' && str2[s] != '\0')
	{
		if (str1[s] != str2[s])
		{
			return (str1[s] - str2[s]);
		}
		s++;
	}
	return (0);
}
/**
 * s_dup - Doubled string
 * @str: string
 * Return: string
 */
char *s_dup(const char *str)
{
	char *pointer;
	const char *copy = str;
	int ln = 0, x;

	if (str == NULL)
		return (NULL);
	while (*copy)
	{
		ln++;
		copy++;
	}

	pointer = malloc(sizeof(char) * (ln + 1));
	if (pointer == NULL)
		return (NULL);
	for (x = 0; x < ln; x++)
		pointer[x] = str[x];
	pointer[ln] = '\0';
	return (pointer);
}
/**
 * s_cat - concat string
 * @x: input
 * @y: input
 * Return: x
 */

char *s_cat(char *x, char *y)
{
	 char *poin = x;

	if (x == NULL || y == NULL)
	{
		return (NULL);
	}

	while (*poin != '\0')
	{
		poin++;
	}

	while (*y != '\0')
	{
		*poin = *y;
		poin++;
		y++;
	}

	*poin = '\0';

	return (x);
}
/**
 * s_copy - copy string
 * @x: input
 * @y: input
 * Return: x
 */
char *s_copy(char *x, char *y)
{
	 int j = 0;

	if (x == NULL || y == NULL)
	{
		return (NULL);
	}

	while (y[j])
	{
		x[j] = y[j];
		j++;
	}
	x[j] = '\0';
	return (x);
}
