#include "monty.h"

/**
 * op_pstr - prints string from stack
 * @stack: stack head
 * @line_number: current line number
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = *stack;
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
