#include "monty.h"

/**
 * read_file - Reads and processes the Monty bytecode file line by line.
 * @file: The file pointer to the Monty bytecode file.
 */
void read_file(FILE *file)
{
	char line[1024], *opcode;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || opcode[0] == '#') /* Ignore comments or empty lines */
			continue;

		execute_opcode(&stack, opcode, line_number, strtok(NULL, " \n\t"));
	}

	free_stack(stack);
}

/**
 * execute_opcode - Executes the given opcode.
 * @stack: Double pointer to the head of the stack.
 * @opcode: The opcode to execute.
 * @line_number: The current line number in the Monty bytecode file.
 * @arg: Argument for the push instruction, if applicable.
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number,
					char *arg)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - Frees the memory allocated for the stack.
 * @stack: Pointer to the head of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	read_file(file);
	fclose(file);

	return (EXIT_SUCCESS);
}
