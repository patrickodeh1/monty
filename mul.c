#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack
 *       with the top element of the stack.
 * @stack: Double pointer to the stack (head of the stack).
 * @line_number: Line number in the bytecode file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	/* Check if there are at least two elements in the stack */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform multiplication */
	temp = *stack;
	result = temp->n * temp->next->n;

	/* Update the stack */
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
