#include "monty.h"

/**
 * op_pchar - prints char at top of stack
 * @stack: stack head
 * @line_number: current line number
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
