#define _GNU_SOURCE
#include "monty.h"

/**
 * run_monty - reads and executes Monty instructions
 * @file: opened Monty file
 * @stack: stack head
 */
void run_monty(FILE *file, stack_t **stack)
{
	char *line = NULL;
	char *opcode;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		g_arg = strtok(NULL, " \t\n");
		execute(opcode, stack, line_number);
	}

	free(line);
}
