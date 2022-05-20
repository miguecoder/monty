#include "monty.h"
/**
 * is_number - check if string received is int or not
 * @token: string to check
 * Return: -1 if sring is not int or 1 if yes
 */
int is_number(char *token)
{
	int i;

	if (token == NULL)
		return (-1);

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] != '-' && isdigit(token[i]) == 0)
		{
			return (-1);
		}
	}
	return (1);
}
/**
 * search_function - Function that get function called
 * @stt: First token (string), of line command
 * @line_number: number of line in file .m
 * Return: 0 function
 */
void (*search_function(char *stt, unsigned int line_number))()
{
	int i;
	char **list_token = NULL, *delim = "\n\t ";

	instruction_t functions[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
	};

	list_token = tk_cm(stt, delim);

	if (strcmp(list_token[0], "push") == 0)
	{
		if (!list_token[1] || is_number(list_token[1]) == -1)
		{
			free(list_token);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		number = atoi(list_token[1]);
	}

	for (i = 0; functions[i].opcode != NULL; i++)
	{
		if (strcmp(functions[i].opcode, stt) == 0)
		{
			return (functions[i].f);
		}
	}
	return (NULL);
}
