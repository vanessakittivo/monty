#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: stack head
 * @line_number: current line number
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
