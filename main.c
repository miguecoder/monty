#include "monty.h"
/**
 * main - Function interpreter for Monty ByteCodes files.
 * @argc: Number of arguments.
 * @argv: List of arguments.
 * Return: 0 alwayls.
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	int line = 1;
	char *buffer = NULL, *unknown = NULL;
	size_t size;
	stack_t *stack = NULL;
	void (*f)(stack_t **stack, unsigned int line_number);

	/*
	 * argv need be lenght = 2
	 * argv[0] = program-name, argv[1] = file-name .m
	 */
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

	for (line = 1; getline(&buffer, &size, file) != -1; line++)
	{
		f = search_function(buffer, line);
		if (f == NULL)
		{
			unknown = strtok(buffer, " ");
			fprintf(stderr, "L%i: unknown instruction %s\n", line, unknown);
			exit(EXIT_FAILURE);
		}
		f(&stack, line);
	}
	fclose(file);
	free(buffer);
	free_stack(&stack);
	return (0);
}
