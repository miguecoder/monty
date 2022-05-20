#include "main.h"
/**
 * count_word - Functions that count how many word have the command
 * @strn: String that contains the line command got
 * Return: number of words.
 */
int count_word(char *strn)
{
	int ct = 0;
	int word = 0;

	while (*strn)
	{
		if (*strn == ' ' || *strn == '\n' || *strn == '\t' || *strn == '='
				|| *strn == ':')
			ct = 0;

		else if (ct == 0)
		{
			ct = 1;
			word++;
		}
		strn++;
	}
	return (word);
}
/**
 * tk_cm - Function that create a tokens for line comand
 * @comand: line of input in linecomand
 * @delim: delimitador
 * Return: array that contents all tokenof line comand
 */
char **tk_cm(char *comand, char *delim)
{
	char **token = NULL;
	int i, words = 0;

	words = count_word(comand);

	token = malloc(sizeof(char *) * (words + 1));
	if (token == NULL)
	{
		free(token);
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token[0] = strtok(comand, delim);
	if (token[0] == NULL)
	{
		free(token);
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 1; i < words + 1; i++)
		token[i] = strtok(NULL, delim);
	return (token);
}
