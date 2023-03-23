#include "monty.h"

/**
 * _mem_alloc - allocates memory block
 * @ptr: pointer to the previous memory
 * @size: the old size
 * @new_size: the new size
 * Return: a pointer to the newly allocated memory
 */
void *_mem_alloc(void *ptr, unsigned int size, unsigned int new_size)
{
	void *res;

	if (new_size == size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		_error(1);
	}
	res = malloc(new_size);
	if (res == NULL)
		_error(1);
	if (ptr == NULL)
	{
		fill(res, '\0', new_size);
		free(ptr);
	}
	else
	{
		memcpy(res, ptr, size);
		free(ptr);
	}
	return (res);
}

/**
 * fill - fill an array with elements
 * @a: the given array
 * @elem: the given element
 * @len: the length of the array
 * Return: pointer to filled array
 */
void *fill(void *a, int elem, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = elem;
		p++;
		i++;
	}
	return (a);
}

/**
 * _free - frees data
 */
void _free(void)
{
	free(data.line);
	data.line = NULL;
	free(data.args);
	data.args = NULL;
	fclose(data.fp);
}
/**
 * _free_list - frees a linked list
 * @stack: a pointer to the linked list
 * Return: nothing
 */
void _free_list(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
