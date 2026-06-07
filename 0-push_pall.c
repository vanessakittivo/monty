#include "monty.h"

/**
 * op_push - pushes an element onto the stack
 * @stack: pointer to pointer to stack head
 * @line_number: current line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int n;
	int i;
	int is_neg;

	if (!g_arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(g_file);
		exit(EXIT_FAILURE);
	}
	i = 0;
	is_neg = 0;
	if (g_arg[0] == '-')
	{
		is_neg = 1;
		i = 1;
	}
	if (!g_arg[i])
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(g_file);
		exit(EXIT_FAILURE);
	}
	while (g_arg[i])
	{
		if (g_arg[i] < '0' || g_arg[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(*stack);
			fclose(g_file);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	(void)is_neg;
	n = atoi(g_arg);
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(g_file);
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->prev = NULL;
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

/**
 * op_pall - prints all values on the stack from top to bottom
 * @stack: pointer to pointer to stack head
 * @line_number: current line number
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
