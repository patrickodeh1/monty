#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	result = first->n + second->n;

	second->n = result;
	*stack = second;
	free(first);
}
