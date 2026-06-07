#include "monty.h"

/**
 * op_pop - removes the top element of the stack
 * @stack: pointer to pointer to stack head
 * @line_number: current line number
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		fclose(g_file);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}
