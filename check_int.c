#include "monty.h"
/**
 * check_int - the funCtion checks if a string can be converted to an integer
 * @str: the source String
 * Return: 0 (success) or 1 (failure)
 */
int check_int(char *str)
{
	size_t idx = 0;

	if (!str)
	{
		return (1);
	}
	for (; str[idx]; idx++)
	{
		if ((str[idx] < 48 || str[idx] > 57) && (str[idx] != '-'))
			return (1);
	}
	return (0);
}
