#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack
 * @stack: pointer to pointer to stack head
 * @line_number: current line number
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		fclose(g_file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
