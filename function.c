#include "main.h"
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
		printf("Error: malloc failed\n");
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
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
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
