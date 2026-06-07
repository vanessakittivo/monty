#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: stack head
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
