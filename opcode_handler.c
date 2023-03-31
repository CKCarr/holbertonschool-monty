#include "monty.h"
/**
  * opcode_handler - function that handles each opcode as it is seen
  *                  and calls function that correlates with each code.
  * @stack: pointer to DLL stack_t stack.
  * Return: void
  */
void opcode_handler(stack_t **stack)
{
	unsigned int i;

	if (*stack == NULL)
	{
		return;
	}

	instruction_t handle[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_int},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{NULL, NULL}
	};

	while (handle[i].opcode != NULL)
	{
		if (strcmp(handle[i].opcode, glob_file.opcode) == 0)
		{
			handle[i].f(stack, glob_file.op_line);
			return;
		}
		i++;
	}
	free(stack);
}
