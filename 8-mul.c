#include "monty.h"

/**
 * op_mul - multiplies the second top element with the top element
 * @stack: stack head
 * @line_number: current line number
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
