#include "monty.h"

/**
 * pall - Prints all values on the stack from the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number (unused).
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; /* Unused parameter */

	/* Traverse and print each element */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
