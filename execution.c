#include "monty.h"
/**
 * free_stack -  frees a dlistint_t list.
 * @stack: pointer to a pointer to the head of a list.
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = (*stack);
		(*stack) = temp->prev;
		free(temp);
	}
}
/**
 * execution - Function that execute the .m file.
 * @argv: arguments
 * Return: void
 **/
void execution(char **argv)
{
	FILE *file = NULL;
	int line = 1;
	char *buffer = NULL, *unknown = NULL;
	size_t size = 0;
	stack_t *stack = NULL;
	void (*f)(stack_t **stack, unsigned int line_number);

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
}
