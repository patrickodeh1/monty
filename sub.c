#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = top->next;

	result = second_top->n - top->n;
	second_top->n = result;

	*stack = second_top;
	(*stack)->prev = NULL;
	free(top);
}
