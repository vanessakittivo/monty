#include "monty.h"

/**
 * op_rotl - rotates stack to the top
 * @stack: stack head
 * @line_number: current line number
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *last;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}
