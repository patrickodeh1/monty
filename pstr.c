#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the stack (head of the stack).
 * @line_number: Line number in the bytecode file.
 */
void pstr(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *current = *stack;

	/* Check if the stack is empty */
	if (current == NULL)
	{
		printf("\n");
		return;
	}

	/* Traverse the stack and print characters */
	while (current != NULL)
	{
		/* Stop printing if the value is 0 or out of ASCII range */
		if (current->n == 0 || current->n < 0 || current->n > 127)
		{
			break;
		}

		/* Print the character corresponding to the ASCII value */
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
