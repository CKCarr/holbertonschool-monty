#include "monty.h"

/**
 * file_parse - Parse a line from a Monty byte code file
 * @line: Pointer to the line string to be parsed
 * @delims: Delimiter characters to tokenize the line
 * @stack: Pointer to the top of the stack
 */
void file_parse(char *line, const char *delims, stack_t **stack)
{
	char *opcode, *arg;
	unsigned int line_num = ++glob_file.op_line;

	opcode = strtok(line, delims);
	if (!opcode)
		return;
	if (opcode[0] == '#')
		return;
	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, delims);
		if (!arg || (*arg && !is_integer(arg)))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_stack(stack, "");
			exit(EXIT_FAILURE);
		}
		push_op(stack, line_num);
	}
}
/**
  * is_integer - function that checks if a digit is an
  * integer
  * @str: string give to check
  * Return: integer
  */
int is_integer(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
