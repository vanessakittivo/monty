#include "monty.h"

/**
 * op_stack - sets mode to stack
 * @stack: stack head
 * @line_number: current line number
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	g_mode = 0;
}

/**
 * op_queue - sets mode to queue
 * @stack: stack head
 * @line_number: current line number
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	g_mode = 1;
}
