#include "main.h"

/**
 * pos_num - check if number is positive
 * @str: input from user
 * Return: 0 or 1
*/
int pos_num(char *str)
{
	int x;

	if (str == NULL)
		return (0);
	for (x = 0; str[x]; x++)
	{
		if (str[x] < '0' || str[x] > '9')
			return (0);
	}
	return (1);
}
