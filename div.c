#include "monty.h"

/**
 * _div - divides the second top element by the top element
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

	if ((*stack)->n == 0)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	exit(EXIT_FAILURE);
}

	a = (*stack)->next->n;
	b = (*stack)->n;

	pop(stack, line_number);
	(*stack)->n = a / b;
}
