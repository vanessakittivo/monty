#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: pointer to pointer to stack head
 * @line_number: current line number
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		fclose(g_file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
