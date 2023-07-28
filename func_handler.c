#include "main.h"

/**
 * add_cmd - the function adds a node_end singly-linked list of the parsed cmds
 * @head: linked list heAd
 * @str: the command parsed.
 * @l: the scripts line number
 * Return: the new node (success) or NULL (failure)
 */

Commands *add_cmd(Commands **head, char *str, int l)
{
	Commands *var = *head;
	Commands *new = NULL;
	char *string;

	new = malloc(sizeof(Commands));
	if (!new)
		return (NULL);
	new->cmd[0] = strdup(strtok(str, "\t"));
	if (!(new->cmd[0]))
	{
		free(new);
		return (NULL);
	}
	string = strtok(NULL, "\t");
	if (string)
	{
		new->cmd[1] = strdup(string);
		if (!(new->cmd[1]))
		{
			free(new->cmd[1]);
			free(new);
			return (NULL);
		}
	}
	else
		new->cmd[1] = NULL;
	new->line_number = l;
	new->next = NULL;
	new->Command_Mode = 0;
	if (!(*head))
	{
		*head = new;
		return (new);
	}
	for (; var->next; var = var->next)
		continue;
	var->next = new;
	return (new);
}

/**
 * is_comment_line - the finction that finds the comments in a line
 * @str:the string line to read
 * Return: 1 (comment found) or 0 (failure)
 */
int is_comment_line(char **str)
{
	int x;

	for (x = 0; (*str)[x] && ((*str)[x] == ' ' || (*str)[x] == '\t'); x++)
		;
	if ((*str)[x] == '#')
	{
		return (1);
	}
	for (x = 0; ((*str)[x] && (*str)[x] != '#'); x++)
		;
	(*str)[x] = '\0';
	return (0);
}

/**
 * handle_cmds - the FunCtion executes the appropriate instruction based
 * on the opcode entered
 * @stack: the PointEr to the stacks double-linked list
 */

void handle_cmds(stack_t **stack)
{
	int index = 0;
	instruction_t ops[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"stack", f_stack},
		{"queue", f_queue},
		{NULL, NULL}
	};
	while (ops[index].opcode)
	{
		if (!strcmp(ops[index].opcode, head->cmd[0]))
		{
			(*ops[index].f)(stack, head->line_number);
			break;
		}
		index++;
	}
	if (!ops[index].opcode)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", head->line_number,
				'\t'head->cmd[0]);
		free_linkedlist(stack);
		exit(EXIT_FAILURE);
	}
}
