#include "monty.h"
/**
 * add - Function that adds the top two elements of the stack
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(tmp->prev)->n = tmp->n + (tmp->prev)->n;
	pop(stack, line_number);
}
/**
 * sub - Function that adds the top two elements of the stack
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(tmp->prev)->n = (tmp->prev)->n - tmp->n;
	pop(stack, line_number);
}
/**
 * mul - Function that adds the top two elements of the stack
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(tmp->prev)->n = (tmp->prev)->n * tmp->n;
	pop(stack, line_number);
}
/**
 * div_ - Function that adds the top two elements of the stack
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/
void div_(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->prev->n = tmp->prev->n / tmp->n;
	pop(stack, line_number);
}
/**
 * mod - Function that adds the top two elements of the stack
 * @stack: element at the top of the stack.
 * @line_number: number of line in file .m
 * Return: void
 **/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->prev->n = tmp->prev->n % tmp->n;
	pop(stack, line_number);
}
