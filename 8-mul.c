#include "monty.h"

/**
 * op_mul - multiplies the second top element with the top element
 * @stack: pointer to pointer to stack head
 * @line_number: current line number
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		fclose(g_file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	op_pop(stack, line_number);
}
