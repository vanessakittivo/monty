#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

	a = (*stack)->n;
	b = (*stack)->next->n;

	pop(stack, line_number);
	(*stack)->n = a + b;
}
