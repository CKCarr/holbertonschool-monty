#include "monty.h"
/**
  * bc_file_parse - function extracts the opcode and
  *  operand
  * @current_line: current line of input file.
  * @delims:  string of characters representing
  * the delimiters
  * @stack_ptr: pointer to a pointer to the top of stack
  * Return: void
  */
void bc_file_parse(char *current_line, const char *delims, stack_t **stack_ptr)
{
	/*Increment the global line counter*/
	glob_file.op_line++;
	/*Set the global reference to the current line*/
	glob_file.line_ref = current_line;
	/*Extract the opcode from the line*/
	glob_file.op_code = strtok(current_line, delims);
	/*Check if the opcode is empty or starts with a comment*/
	if (!glob_file.op_code || glob_file.op_code[0] == '#')
	{
		return;
	}
	/*Extract the operand (if any) from the line*/
	glob_file.op_arg = strtok(NULL, delims);
	/*Call the opcode handler function to process the instruction*/
	opcode_handler(stack_ptr);
	if (opcode_handler(stack_ptr) == -1)
    {
        // Error occurred during instruction processing
        fprintf(stderr, "L%d: unknown instruction %s\n", glob_file.op_line, glob_file.op_code);
        exit(EXIT_FAILURE);  // or return -1 if you want to handle the error in a higher-level function
    }
}
