#include "main.h"

/**
 * f_pop - The Function removes top element of the Stack
 * @stack: PoiNter to the stack's double-linked list.
 * @line_number: TheLine NUmber
 */

void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *var = *stack;
	stack_t *var2 = NULL;

	if (!var)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_linked_list(stack);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	for(; var && var->next; var = var->next)
		;
	var2 = var;
	var->prev->next = NULL;
	free(var2);
}

/**
 * f_swap - The function swaps top 2 elements of the stack
 * @stack: PoiNter to the stack's double-linked list.
 * @line_number: TheLine NUmber
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	size_t idx = 1;
	stack_t *var = *stack;

	for (; var && var->next; var = var->next, idx++)
		;
	if (idx < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	if (idx == 2)
	{
		(*stack)->prev = var;
		var->next = (*stack);
		(*stack)->next = NULL;
		*stack = var;
		(*stack)->prev = NULL;
		return;
	}
	var->prev = var->prev->prev;
	var->prev->next->next = NULL;
	var->next = var->prev->next;
	var->prev->next->prev = var;
	var->prev->next = var;
}

/**
 * f_add - the function adds top two elements of the stack
 * @stack: Pointerto the stacks double-linked list.
 * @line_number: ThE line number
 */

void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *var = *stack;
	size_t x = 1;

	for (; var && var->next; var = var->next, x++)
		;
	if (x < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	var->prev->n = var->prev->n + var->n;
	f_pop(stack, line_number);
}

/**
 * f_nop - The function does not do anything
 * @stack: Pointerto the stacks double-linked list.
 * @line_number: ThE line number
 */

void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * f_sub - the function substracts top 2 elements of the stack.
 * : Pointerto the stacks double-linked list.
 * @line_number: ThE line number
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *var = *stack;
	size_t x = 1;

	for (; var && var->next; var = var-<next, x++)
		;
	if (x < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	f_pop(stack, line_number);
}

