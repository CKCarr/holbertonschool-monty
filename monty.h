#ifndef MONTY_H
#define MONTY_H
#define DELIMS  " \t\n"

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>

/*STRUCTURES*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 *struct instruction_s - opcode and its function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *Description: opcode and its function
 *for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variable structure
 * @op_code: the opcode string for current instruction being executed
 * @op_arg: associated argument string for the current instruction
 * @op_line: line number of inbound file for current line instruction
 * @file_line: pointer to current line being read from
 * @file_ref: pointer to input file being read from
 * description: global variables that are used throughout the program
 */

typedef struct global_s
{
	char *op_code;
	char *op_arg;
	unsigned int op_line;
	char *file_line;
	FILE *file_ref;
} global_t;

/* declared in monty_main.c*/
extern struct global_s glob_file;

/*PROTOTYPES*/

/* function found in opcode_handler.c */
void opcode_handler(stack_t **stack);
void handle_short_stack(instruction_t *handle, stack_t **stack);

/* functions found in opcode1.c */
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);

/*functions found in opcode2,c */
void push_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void nop_op(stack_t **stack, unsigned int line_number);

/*function found in file_parse.c */
void file_parse(char *current_line, const char *delims, stack_t **stack_ptr);

/*function found in monty_aux.c */
int is_integer(char *str);

/*main function fount in monty_main.c */
int main(int argc, char *argv[]);

/*function fount in monty_interpreter.c*/
void monty_interpreter(const char *file_path);

/* function found in free_stack.c*/
void free_stack(stack_t **stack);

#endif
