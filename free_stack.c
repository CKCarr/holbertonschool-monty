#include "monty.h"
/**
 * free_stack - frees all nodes in a DLL stack
 * @stack: pointer to DLL stack_t stack
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *free_s;

	if (*stack)
	{
		while (*stack)
		{
			free_s = (*stack);
			free(*stack);
			(*stack) = NULL;
			(*stack) = free_s;
		}
	}
	if (glob_file.file_line)
	{
		free(glob_file.file_line);
	}
	if (glob_file.file_ref && feof(glob_file.file_ref) == 0)
	{
		fclose(glob_file.file_ref);
		glob_file.file_ref = NULL;
	}
}
