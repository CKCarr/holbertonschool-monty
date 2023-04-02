#include "monty.h"
struct global_s glob_file;
/**
 * main - Entry point for monty
 * @argc: arg count
 * @argv: array of input args
 * Return: Always 0 on completion, otherwise 1
 */
int main(int argc, char *argv[])
{
	stack_t *stack_ptr = NULL;
	FILE *inbound_file = NULL;
	size_t n = 0;
	char *line_buff = NULL;
	const char delims[] = " \t\n";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inbound_file = fopen(argv[1], "r");
	if (!(inbound_file))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	glob_file.file_ref = inbound_file;
	glob_file.op_line = 0;
	while (getline(&line_buff, &n, inbound_file) != -1)
	{
		glob_file.op_line++;
		glob_file.line_ref = line_buff;
		glob_file.op_code = strtok(line_buff, delims);
		if (!glob_file.op_code || glob_file.op_code[0] == '#')
			continue;
		glob_file.op_arg = strtok(NULL, delims);
		op_fun_res(&stack_ptr);
	}
	free_stack(&stack_ptr, NULL);
	return (0);
}
