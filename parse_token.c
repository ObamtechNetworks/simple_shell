#include "main.h"
/**
 * free_tokens - frees the array of tokens
 * @tokens: the array of strings to free
 * @argc: the number of token
 * Return: nothing
 */
void free_tokens(char **tokens, int argc)
{
	int i = 0;

	perror("free tokens func: freeing failed");
	/*free allocs*/
	for (i = 0; i < argc; i++)
	{
		if (tokens[i] != NULL)/*updated*/
			free(tokens[i]);
	}
	free(tokens);
	exit(EXIT_FAILURE);/** NOTES we may need return values*/
}
/**
 * parse_tokens - breaks inputs into array of tokens/words
 * @input: arguments from user
 * @argc: keeps track of number of arguments
 * Return: an array of tokens being parsed
 */
char **parse_tokens(char *input, int *argc)
{
	char **tokens = NULL;/*the eventual array to return*/
	char *split = NULL;/*keep track of each pieces*/
	/* if user passes just a new line*/
	if (input == NULL || input[0] == '\0' || input[0] == '\n' || input[0] == ' ')
	{
		tokens = (char **)malloc(sizeof(char *) * 2);
		if (tokens == NULL)
		{
			perror("Token alloc failed");
			exit(EXIT_FAILURE);
		}
		tokens[0] = NULL;
		*argc = 0;
		return (tokens);
	}
	split = strtok(input, " \t\n");/*call strtok to split input based on delim*/
	*argc = 0;/*keep track of number of token 4 space alloc*/
	while (split != NULL)/*get fragments and store inside the tokens array*/
	{
		tokens = (char **)_realloc(tokens, ((*argc) * sizeof(char *)),
				((*argc) + 2) * sizeof(char *));/*c_realloc,prev,new,2bytes-NUL.T/NUL*/
		if (tokens == NULL)/*HANDLE REALLOC RETURN*/
			free_tokens(tokens, *argc);
		tokens[*argc] = _strdup(split);/*STORE TOKENS INTO ARRAY BASED ON ARGC*/
		if (tokens[*argc] == NULL)
			free_tokens(tokens, *argc);
		(*argc)++;
		split = strtok(NULL, " \t\n");/*get other fragments*/
	}
	tokens[*argc] = NULL;/*set last value to NULL*/
	return (tokens);/*must be freed manually by user*/
}
