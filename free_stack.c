#include "monty.h"
/**
 * free_stack - frees all nodes in a DLL stack
 * @stack: pointer to DLL stack_t stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack, *tmp;

	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}

	*stack = NULL;
}
