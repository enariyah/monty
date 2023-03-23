#include "monty.h"
/**
 * swap - swaps the two top values
 * @stack: the pointer to the linked list
 * @line_num: the line number
 * Return: nothing
 */
void swap(stack_t **stack,
	unsigned int line_num __attribute__((unused)))
{
	stack_t *second;
	stack_t *first;

	if (*stack == NULL || (*stack)->next == NULL)
		_error(8);
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	(*stack) = second;
}
