#include "monty.h"
/**
  * swap_op - function that swaps the top 2 elements of the stack.
  * @stack: stack struct DLL.
  * @line_number:
  *
  * Return: void
  */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int count = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = *stack;
	}
	temp->prev = temp->next;
	temp->next = stack;
	(*stack)->prev = temp;
	(*stack) = temp;
}
/**
  * add_op - function that adds the top two
  * @stack: stack structure DLL
  * @line_number: number of line in the file.
  * Return: void.
  */
void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *current = *stack;
	int count = 0;

	if (*stack == NULL)
	{
		return;
	}
	while (current)
	{
		count++;
		current = current->next;
	}
	if (count < 2)
	{
		if (temp == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	(temp->next)->n = temp->n + (temp->next)->n;
	op_pop(stack, line_number);
}
/**
  * nop_op - function that doesn't do anything.
  * @stack: stack structure DLL.
  * @line_number: number of line in the file.
  * Return: void
  */
void nop_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
  * push_op - insert element to top of the stack.
  * @stack: pointer to the stack.
  * @line_number: current line number in file.
  * Return: void
  */
void push_op(stack_t *stack, unsigned int line_number)
{
	char *arg;
	int val;
	stack_t *new_node;

	arg = strtok(NULL, " $\t\n");
	if (!arg)
	{
		fprintf(stderr, " L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!isdigit(arg[0]) && arg[0] != '-')
	{
		fprintf(stderr, " L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = val;
	new_node->prev = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;

	}
	*stack = new_node;
}