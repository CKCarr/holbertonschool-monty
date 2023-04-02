#include "monty.h"
struct global_s glob_file;
/**
  * monty_interpreter - reads each line of the input
  * file, parses the opcode and argument using
  * file_parse, and then handles the instruction
  * using opcode_handler.
  * @file_path:path to the input file, passed as arg
  * Return: void
  */
void monty_interpreter(const char *file_path)
{
	FILE *file = fopen(file_path, "r");
	char *line = NULL;
	size_t line_size = 0;
	ssize_t read;
	stack_t *stack = NULL;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &line_size, file)) != -1)
	{
		printf("Processing line: %s", line);
		/* Parse current line ofinput file */
		file_parse(line, " \t\n", &stack);
		/* Handle current opcode and its arg*/
		opcode_handler(&stack);
	}
	/* Free memory and close the input file */
	free(line);
	fclose(file);
}
