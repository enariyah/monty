#include "monty.h"
/**
 * parser - process and parse line
 * @stack: the stack
 * Return: integer
 */
int parser(stack_t **stack)
{
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while ((inst + i)->opcode)
	{
		if (strcmp((inst + i)->opcode, *data.args) == 0)
		{
			(inst + i)->f(stack, data.line_num);
			return (0);
		}
		i++;
	}
	_error(4);
	return (1);
}
