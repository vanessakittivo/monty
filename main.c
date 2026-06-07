#define _GNU_SOURCE
#include "monty.h"

/**
 * main - entry point for Monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success
 */
int main(int argc, char **argv)
{
	FILE *file;
	stack_t *stack;

	stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	run_monty(file, &stack);
	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
