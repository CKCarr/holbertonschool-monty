#include "monty.h"

/**
 * pall_op - prints all values of stack starting at top
 * @stack: double pinter to top of the stack
 * @line_number: cureent line # in file
 */

void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	current = (*stack);
	while (current != NULL)
	{
		printf("%d\n", current->n);
		fflush(stdout);
		current = current->next;
	}
}

/**
 * pint_op - function that prints the value at the top of the slack
 * @line_number: Number of lines in file
 * @stack: double pointer to the top of the stack.
 */

void pint_op(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_op - function removes the top element of the stack
 * @line_number: current line_number in file
 * @stack: double pointer to the top of the stack.
 */

void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	if (*stack == NULL)
	{
		glob_file.op_arg = NULL;
	}
}
