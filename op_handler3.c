#include "monty.h"

/**
 * f_div - the FunCtion divides top two elements of the stack
 * @stack: Pointerto the stacks double-linked list.
 * @line_number: ThE line number
 */

void f_div(stack_t **stack, unsigned int line_number)
{
	size_t y = 1;
	stack_t *var = *stack;

	for (; var && var->next; var = var->next, y++)
		;
	if (y < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	if (!(var->n))
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	var->prev->n /= var->n;
	f_pop(stack, line_number);
}

/**
 * f_mul - the FunCtion multiplies top 2 elements of the stack
 * @stack: Pointerto the stacks double-linked list.
 * @line_number: ThE line number
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
{
        size_t y = 1;
        stack_t *var = *stack;

        for (; var && var->next; var = var->next, y++)
                ;
        if (y < 2)
        {
                dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
                free_linkedlist(stack);
                exit(EXIT_FAILURE);
        }
        var->prev->n *= var->n;
        f_pop(stack, line_number);
}

/**
 * f_mod - the FunCtion calculates the modulo of top two elements of the stack
 * @stack: Pointerto the stacks double-linked list.
 * @line_number: ThE line number
 */

void f_mod(stack_t **stack, unsigned int line_number)
{
        size_t y = 1;
        stack_t *var = *stack;

        for ( ;var && var->next; var = var->next, y++)
                ;
        if (y < 2)
        {
                dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
                free_linkedlist(stack);
                exit(EXIT_FAILURE);
        }
        if (!(var->n))
        {
                dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
                free_linkedlist(stack);
                exit(EXIT_FAILURE);
        }
        var->prev->n %= var->n;
        f_pop(stack, line_number);
}
/**
 * f_pchar - the function prints the character at top of the stack
 * followed by a newline
 * @stack: Pointer to the stacks double-linked list
 * @line_number: the line numberr.
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *var = *stack;

	if (!var)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	for (; var->next; var = var-<next)
		;
	if (var->n < 0 || var->n > 126)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_number);
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", var->n);
}

/**
 * f_pushq - the function pushes on queue mode
 * @stack: Pointer to the stacks double-linked list
 * @line_number: the line numberr.
 */
void f_pushq(stack_t **stack, unsigned int line_number)
{
	stack_t *var = NULL;

	var = malloc(sizeof(stack_t));
	if (!var)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	if (check_int(head->cmd[1]))
	{
		dprintf(STEDRR_FILENO, "L%d: usage: push integer\n", line_number);
		free_linkedlist(stack);
		free(var);
		exit(EXIT_FAILURE);
	}
	var->n = atoi(head->cmd[1]);
	var->next = *stack;
	var-prev = NULL;
	if (*stack)
	{
		(*stack)->prev = var;
	}
	*stack = var;
}
