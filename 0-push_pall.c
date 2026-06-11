#include "monty.h"

/**
 * create_node - creates a new stack node
 * @n: value to store
 *
 * Return: pointer to new node
 */
stack_t *create_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

/**
 * op_push - pushes an integer to the stack
 * @stack: stack head
 * @line_number: current line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *temp;

	if (is_integer(g_arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = create_node(atoi(g_arg));

	if (g_mode == 0 || *stack == NULL)
	{
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
		return;
	}

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;
	new_node->prev = temp;
}
/**
 * op_pall - prints all stack values
 * @stack: stack head
 * @line_number: current line number
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
