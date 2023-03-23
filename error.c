#include "monty.h"
/**
 * _error - printts error
 * @err_code: error code
 * Return: nothing
 */
void _error(short int err_code)
{
	switch (err_code)
	{
	case 1:
		fprintf(stderr, "Error: malloc failed\n");
		_free();
		break;
	case 2:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 3:
		fprintf(stderr, "Error: Can't open file %s\n", data.fl_name);
		break;
	case 4:
		fprintf(stderr, "L%d: unknown instruction %s\n",
			data.line_num, data.args[0]);
		_free();
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", data.line_num);
		_free();
		break;
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n", data.line_num);
		_free();
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n", data.line_num);
		_free();
		break;
	case 8:
		fprintf(stderr, "L%d: can't swap, stack too short\n", data.line_num);
		_free();
		break;
	default:
		break;
	}
	exit(EXIT_FAILURE);
}
