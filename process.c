#include "monty.h"
/**
 * push - adds a new node at the beginning of a linked list
 * @stack: a pointer to the linked list
 * @line_num: the line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		_error(1);
	if (_isdigit(data.args[1]) > 0)
		_error(5);
	new->n = atoi(data.args[1]);
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		new->prev = NULL;
	}
	*stack = new;
}

/**
 * pall - prints all elements of a doubly list
 * @stack: the pointer to the head
 * @line_num: the line number
 * Return: nothing
 */
void
pall(stack_t **stack,
	unsigned int line_num __attribute__((unused)))
{
	stack_t *loc;

	loc = *stack;
	while (loc)
	{
		printf("%d\n", loc->n);
		loc = loc->next;
	}
}
/**
 * pint - prints from bottom to top
 * @stack: the pointer to the head
 * @line_num: the line number
 * Return: nothing
 */
void pint(stack_t **stack,
	unsigned int line_num __attribute__((unused)))
{
	if (*stack == NULL)
		_error(5);
	fprintf(stdout, "%d\n", (*stack)->n);
}
/**
 * pop - prints from bottom to top
 * @stack: the pointer to the head
 * @line_num: the line number
 * Return: nothing
 */
void pop(stack_t **stack,
	unsigned int line_num __attribute__((unused)))
{
	stack_t *tmp;

	if (*stack == NULL)
		_error(7);
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * nop - does nothing
 * @stack: the stack
 * @line_num: the line number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void) line_num;
	(void) stack;
}
