#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

/**
 * struct data_s - data instance
 * @line: the readed line
 * @args: the arguments
 * @line_num: line number
 * @fp: the file
 * @fl_name: fl_name
 * Description: data instance, line, args
 */
typedef struct data_s
{
	char *line;
	char **args;
	char *fl_name;
	int line_num;
	FILE *fp;
} data_i;

extern data_i data;

int parser(stack_t **stack);
void *_mem_alloc(void *ptr, unsigned int old_size, unsigned int new_size);
void push(stack_t **stack, unsigned int line_num);
void _error(short int err_code);
void _free(void);
void pall(stack_t **stack, unsigned int line_num);
void _free_list(stack_t *stack);
int split_l(void);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
int _isdigit(char *str);
void nop(stack_t **stack, unsigned int line_num);
void _error(short int err_code);
void *fill(void *a, int el, unsigned int len);

#endif
