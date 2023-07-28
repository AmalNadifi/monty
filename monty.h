#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define _POSIX_C_SOURCE 200809L

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct CommandNode - This structure represents a node in a singly linked
 * list for storing parsed script commands, including mode, line number,
 * command, and argument.
 * @line_number: line number of the command in the script.
 * @cmd: Array containing the command and its argument.
 * @Command_Mode: the command mode to be chosen by the user.
 * @next: Pointer to the next node in the linked list.
 * Return: ThE address of linked list.
 */

typedef struct CommandNode
{
	char *cmd[2];
unsigned int line_number;
unsigned int  Command_Mode;
	struct CommandNode *next;
} Commands;
extern Commands *head;
Commands *add_cmd(Commands **head, char *s, int i);
void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
void f_nop(stack_t **stack, unsigned int line_number);
void handle_cmds(stack_t **stack);
void free_linkedlist(stack_t **stack);
void f_sub(stack_t **stack, unsigned int line_number);
void f_div(stack_t **stack, unsigned int line_number);
void f_mul(stack_t **stack, unsigned int line_number);
void f_mod(stack_t **stack, unsigned int line_number);
void f_pchar(stack_t **stack, unsigned int line_number);
void f_pstr(stack_t **stack, unsigned int line_number);
void f_rotl(stack_t **stack, unsigned int line_number);
void f_rotr(stack_t **stack, unsigned int line_number);
void f_stack(stack_t **stack, unsigned int line_number);
void f_queue(stack_t **stack, unsigned int line_number);
void f_pushq(stack_t **stack, unsigned int line_number);
int is_comment_line(char **s);
int check_int(char *str);

#endif /*MONTY_H*/

