#include "monty.h"

/**
 * f_push - the function pushes agiven element to the Stack
 * @stack: Pointer to the stack's double-linkedlist
 * @line_number: CurrEnt line number.
 */

void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = NULL;
	stack_t *tempNode = *stack;

	/* Checking if the stack is in the queue mode*/
	if (head->Command_Mode)
	{
		f_pushq(stack, line_number);
		return;
	}
	element = malloc(sizeof(stack_t));
	if (!element)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	if (check_int(head->cmd[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_linkedlist(stack);
		free(element);
		exit(EXIT_FAILURE);
	}
	element->n = atoi(head->cmd[1]);
	element->next = NULL;
	/* if stack is empty make the new element the top of it*/
	if ((!stack))
	{
		element->prev = *stack;
		*stack = element;
		return;
	}
	/* if the stack is not empty traverse the stack to find the lastone */
	while (tempNode->next)
	{
		tempNode = tempNode->next;
	}
	tempNode->next = element;
	element->prev = tempNode;
}
 /**
  * f_pall -the function prints the stacks values from thetop
  * @stack: the pointer to the stakcs double-linked list.
  * @line_number: the CurrenT line number.
  */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack; /* to traverse the stack*/
	(void)line_number;

	if (ptr == NULL)
		return; /* if stack is empty there is nothing to print*/
	for (; ptr->next != NULL; ptr = ptr->next)
		;
	for (; ptr != NULL; ptr = ptr->prev)
	{
		printf("%d\n", ptr->n);
	}
}

 /**
  * free_linkedlist -the function frees all nodes of
  * a linked list and associated data
  * @stack: the POInter to the stack's double-linkedlist.
  */

void free_linkedlist(stack_t **stack)
{
	stack_t *node = NULL;
	Commands *cmd = NULL;

	while (*stack != NULL)
	{
		node = *stack;
		*stack = (*stack)->next;
		free(node);
	}
	while (head != NULL)
	{
		cmd = head;
		head = head->next;
		free(cmd->cmd[1]);
		free(cmd->cmd[0]);
		free(cmd);
	}
}

/**
 * f_pint - the function adds at the end of a list
 * @stack: Pointer to the stack's double-linked list.
 * @line_number: The line numBer.
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *var = *stack;

	if (!var)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
	for (; var->next; var = var->next)
		;
	printf("%d\n", var->n);
}
