#include "monty.h"
#include <stdio.h>

/**
 * global data - data instances
 */
data_i data;
/**
 * main - main function
 * @ac: arguments count
 * @av: arguments vector
 * Return: exit on both success and failure
 */
int main(int ac, char **av)
{
	ssize_t n_read = 1;
	size_t length = 0;
	stack_t *stack = NULL;

	memset((void *) &data, 0, sizeof(data));
	if (ac != 2)
		_error(2);
	data.fl_name = av[1];
	data.fp = fopen(data.fl_name, "r");
	if (data.fp == NULL)
		_error(3);
	while ((n_read = getline(&data.line, &length, data.fp)) != -1)
	{
		if (*data.line == '\n')
			continue;
		data.line_num++;
		free(data.args);
		if (split_l() < 0)
			continue;
		if (*data.args == NULL)
			continue;
		parser(&stack);
	}
	_free();
	_free_list(stack);
	return (EXIT_SUCCESS);
}
