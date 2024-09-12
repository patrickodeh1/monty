#include "monty.h"

/**
 * mod - Computes the remainder of the division of the second top element
 *       of the stack by the top element of the stack.
 * @stack: Double pointer to the stack (head of the stack).
 * @line_number: Line number in the bytecode file.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	/* Check if there are at least two elements in the stack */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if the top element is zero */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform modulo operation */
	temp = *stack;
	result = temp->next->n % temp->n;

	/* Update the stack */
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
