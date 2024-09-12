#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 * @arg: The argument for the push instruction.
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	int value;
	stack_t *new_node;

	/* Check if the argument is valid */
	if (arg == NULL || (!isdigit(arg[0]) && arg[0] != '-' && !isdigit(arg[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg); /* Convert the argument to an integer */

	/* Create a new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Insert at the top of the stack */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
