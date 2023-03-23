#include "monty.h"

#define DELIMITER " \n\t\a"
/**
 * split_l - splits line to tokens
 * Return: positive or negative number in case of success or failure
 */
int split_l(void)
{
	char *tok;
	size_t size = 4, new_size, i = 0;

	data.args = malloc(size * sizeof(char *));
	if (data.args == NULL)
		_error(1);
	tok = strtok(data.line, DELIMITER);
	while (tok)
	{
		data.args[i++] =  tok;
		if (i >= size)
		{
			new_size = size * 2;
			data.args = _mem_alloc(data.args, size * sizeof(char *),
					new_size * sizeof(char *));
			if (data.args == NULL)
				_error(1);
			size = new_size;
		}
		tok = strtok(NULL, DELIMITER);
	}
	data.args[i] = NULL;
	if (**data.args == '#')
		return (-1);
	return (0);
}
#undef DELIMITER

/**
 * _isdigit - checks for a digit from 0 to 9
 * @str: the integer to be checker
 * Return: 1 if is digit, 0 otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (isdigit(*str) == 0)
			return (1);
		i++;
	}
	return (0);
}
