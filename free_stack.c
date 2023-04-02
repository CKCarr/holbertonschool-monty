#include "monty.h"
/**
 * free_stack - free DLL type stack
 * @stack: DLL type stack head
 * @messg: associated exit message
 * Return: void
 */
void free_stack(stack_t **stack, char *messg)
{
	stack_t *scrubber;

	if (messg)
	{
		if (messg[0] == '!')
		{
			messg++;
			fprintf(stderr, "L%d%s%s\n", glob_file.op_line, messg, glob_file.op_code);
		}
		else
			fprintf(stderr, "L%d%s", glob_file.op_line, messg);
	}
	if (glob_file.line_ref)
		free(glob_file.line_ref);
	fclose(glob_file.file_ref);
	if (*stack)
	{
		while (*stack)
		{
			scrubber = (*stack)->next;
			free(*stack);
			(*stack) = scrubber;
		}
	}
	if (messg)
		exit(EXIT_FAILURE);
	else
		return;
}
