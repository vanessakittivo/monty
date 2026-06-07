#define _GNU_SOURCE
#include "monty.h"

/**
 * g_arg - global opcode argument
 */
char *g_arg = NULL;

/**
 * g_file - global opened file
 */
FILE *g_file = NULL;

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
	char *line;
	char *opcode;
	size_t len;
	unsigned int line_number;
	stack_t *stack;

	line = NULL;
	len = 0;
	line_number = 0;
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

	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		opcode = strtok(line, " \t\n");

		if (opcode == NULL)
			continue;

		g_arg = strtok(NULL, " \t\n");

		execute(opcode, &stack, line_number);
	}

	free(line);
	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
