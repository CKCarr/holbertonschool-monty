#include "monty.h"
/**
  * file_parse - function extracts the opcode and
  *  operand
  * @current_line: current line of input file.
  * @delims:  string of characters representing
  * the delimiters
  * @stack_ptr: pointer to a pointer to the top of stack
  * Return: void
  */
void file_parse(char *current_line, const char *delims, stack_t **stack_ptr)
{
	/*Increment the global line counter*/
	glob_file.op_line++;
	/*Set the global reference to the current line*/
	glob_file.file_line = current_line;
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
}
