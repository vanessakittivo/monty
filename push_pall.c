#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 * @arg: the argument (integer as string)
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int value;

	if (arg == NULL || !is_integer(arg))
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
{
	printf("%d\n", current->n);
	current = current->next;
}
}
