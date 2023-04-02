#include "monty.h"
/**
  * file_parse - function parse opcode and operand
  * @current_line: current line of input file.
  * @delims:  string of char delims
  * @stack_ptr: pointer to a pointer to the top of stack
  * Return: void
  */
void file_parse(char *current_line, const char *delims, stack_t **stack_ptr )
{
	char *opcode = NULL, *operand = NULL;
	long int_value = 0;

	++glob_file.op_line;
	glob_file.file_line = current_line;
	opcode = strtok(current_line, delims);
	if (!opcode || opcode[0] == '#')
		return;
	operand = strtok(NULL, delims);
	printf("Operand: %s\n", operand);
	if (!operand)
		glob_file.op_arg = NULL;
	else
	{
		if (is_integer(operand))
		{
			int_value = strtol(operand, NULL, 10);
			glob_file.op_arg = (void *)(intptr_t)int_value;
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", glob_file.op_line);
			exit(EXIT_FAILURE);
		}
	}
	glob_file.op_code = opcode;
	if (strcmp(opcode, "push") == 0)
	{
		push_op(stack_ptr, glob_file.op_line);
	}
}
