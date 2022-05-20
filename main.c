#include "monty.h"
/**
 * main - Function interpreter for Monty ByteCodes files.
 * @argc: Number of arguments.
 * @argv: List of arguments.
 * Return: 0 alwayls.
 */
int main(int argc, char **argv)
{
	/*
	 * argv need be lenght = 2
	 * argv[0] = program-name, argv[1] = file-name .m
	 */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	execution(argv);
	return (0);
}
