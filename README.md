# holbertonschool-monty
0x19. C - Stacks, Queues - LIFO, FIFO
Learning Objectives:
	*What do LIFO and FIFO mean.
	*What is a stack, and when to use it.
	*What is a queue, and when to use it.
	*What are the common implementations of stacks and queues.
	*What are the most common use cases of stacks and queues.
	*What is the proper way to use global variables.
________________________________________________________
The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python).
It relies on a unique stack, with specific instructions to manipulate it.
The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension.
Most of the industry uses this standard but it is not required by the specification of the language.
There is not more than one instruction per line.
There can be any number of spaces before or after the opcode and its argument:
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
_______________________________________________________
		The monty program
		Usage: monty file
_______________________________________________________
Compilation & Output

    Your code will be compiled this way:

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty

    Any output must be printed on stdout
    Any error message must be printed on stderr
_______________________________________________________
/mnt/c/Users/Crysk/Downloads/MONTYcollab.drawio.pdf





Tasks:
0. push, pall
    The push opcode

The opcode push pushes an element to the stack.

The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the stack.

1. pint
The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

2. pop
The pop opcode

The opcode pop removes the top element of the stack.

3. swap
The swap opcode

The opcode swap swaps the top two elements of the stack.

4. add
The add opcode

The opcode add adds the top two elements of the stack.

5. nop
The nop opcode

The opcode nop doesn’t do anything.

-------------------------------------------------------
