#include "monty.h"

struct global_s glob_file;

/**
 * main - Entry point for monty
 * @argc: arg count
 * @argv: array of input args
 * Return: Always 0 on completion, otherwise 1 on exit fail
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_interpreter(argv[1]);

	return (0);
}
