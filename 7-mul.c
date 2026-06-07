#include "monty.h"

/**
 * op_div - divides the second top element by the top element
 * @stack: pointer to pointer to stack head
 * @line_number: current line number
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(*stack);
		fclose(g_file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		fclose(g_file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	op_pop(stack, line_number);
}
