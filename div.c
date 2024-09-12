#include "monty.h"

/**
 * div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = second_top->n / top->n;
	second_top->n = result;

	*stack = second_top;
	(*stack)->prev = NULL;
	free(top);
}
