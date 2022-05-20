#include "monty.h"
/**
 * push -function that adds a new node at the end of stack
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = number;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		(*stack)->next = new;
		new->prev = *stack;
		*stack = new;
	}
	(void)line_number;
}
/**
 * pall - Function that print the elements of a stack
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}
/**
 * pint -  prints the value at the top of the stack
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	if (tmp != NULL)
		printf("%d\n", tmp->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - Function that delete the value at top of stack
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->prev;

	if ((*stack) != NULL)
		(*stack)->next = NULL;

	free(tmp);

	(void)line_number;
}
/**
 * swap - Function that swaps the top two elements of the stack.
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/
void swap(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = i;
	(void)line_number;
}
