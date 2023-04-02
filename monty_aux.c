#include "monty.h"
/**
  * is_integer - function that checks if a digit is an
  * integer
  * @str: string give to check
  * Return: integer
  */
int is_integer(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	if (*str == '-' || *str == '+')
	{
		str++;
	}

	while (*str != '\0')
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
