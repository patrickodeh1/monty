#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: Double pointer to the stack (head of the stack).
 * @line_number: Line number in the bytecode file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if the value is within the ASCII range */
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the character corresponding to the ASCII value */
	printf("%c\n", (*stack)->n);
}
