#include "monty.h"
/**
  * handle_short_stack -checks if stack is too short for certain opcodes
  * @handle: instruction handle struct for certain codes
  * @stack: pointer to  head of stack
  *
  *
  */
void handle_short_stack(instruction_t *handle, stack_t **stack)
{
	
	unsigned int i = 0;

	if (strcmp(glob_file.op_code, handle[i].opcode) == 0)
	{
		if ((strcmp(handle[i].opcode, "pint") == 0 ||
			strcmp(handle[i].opcode, "pop") == 0 ||
			strcmp(handle[i].opcode, "swap") == 0 ||
			strcmp(handle[i].opcode, "add") == 0) &&
			(*stack == NULL || (*stack)->next == NULL))
		{
			fprintf(stderr, "L%d: can't %s, stack too short\n",
				glob_file.op_line, glob_file.op_code);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
}
/**
  * opcode_handler - function handles opcode
  * and calls function that correlates
  * @stack: pointer to DLL stack_t stack.
  * Return: void
  */
void opcode_handler(stack_t **stack)
{
	instruction_t handle[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{NULL, NULL}
	};
	unsigned int i = 0;

	if (*stack == NULL)
	{
		return;
	}
	while (handle[i].opcode != NULL)
	{
		if (strcmp(glob_file.op_code, handle[i].opcode) == 0)
		{
			handle_short_stack(&handle[i], stack);
			handle[i].f(stack, glob_file.op_line);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
		glob_file.op_line, glob_file.op_code);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
