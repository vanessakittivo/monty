#include "monty.h"

FILE *g_file = NULL;
char *g_arg = NULL;

/**
 * free_stack - frees all nodes in the stack
 * @stack: pointer to head of stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/**
 * run_opcode - finds and executes the matching opcode function
 * @stack: pointer to pointer to stack head
 * @opcode: the opcode string
 * @line_number: current line number
 */
void run_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int i;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	fclose(g_file);
	exit(EXIT_FAILURE);
}

/**
 * main - entry point for the monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	stack_t *stack;
	char *line;
	char *opcode;
	size_t len;
	ssize_t read;
	unsigned int line_number;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	g_file = fopen(argv[1], "r");
	if (!g_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	line = NULL;
	len = 0;
	line_number = 0;
	while ((read = getline(&line, &len, g_file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n\r");
		if (!opcode || opcode[0] == '#')
			continue;
		g_arg = strtok(NULL, " \t\n\r");
		run_opcode(&stack, opcode, line_number);
	}
	free(line);
	free_stack(stack);
	fclose(g_file);
	return (EXIT_SUCCESS);
}
