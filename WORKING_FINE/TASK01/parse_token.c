#include "main.h"

/**
 * handle_memory_allocation_failure - frees the emory
 * @tokens: A pointer to an array of character pointers
 * @argc: keeps track of the number of arguments
 */
void handle_memory_allocation_failure(char **tokens, int argc)
{
	int i = 0;

	perror("Token allocation failed");

	for (; i < argc; i++)
	{
		if (tokens[i] != NULL)
			free(tokens[i]);
	}

	free(tokens);
	exit(EXIT_FAILURE);
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

	if (input == NULL || input[0] == '\0' || input[0] == '\n' || input[0] == ' ')
	{
		tokens = (char **)malloc(sizeof(char *) * 2);
		if (tokens == NULL)
			handle_memory_allocation_failure(tokens, *argc);
		tokens[0] = NULL;
		*argc = 0;
		return (tokens);
	}
	split = strtok(input, " \t\n");
	*argc = 0;/*keep track of number of token 4 space alloc*/
	/*get other fragments and store inside the tokens array*/
	while (split != NULL)
	{
		/*custom realloc,prev size,&the new size,2bytes 4 NULL.T/NULL*/
		tokens = (char **)_realloc(tokens, ((*argc) * sizeof(char *)),
				((*argc) + 2) * sizeof(char *));
		/*HANDLE REALLOC RETURN*/
		if (tokens == NULL)
			handle_memory_allocation_failure(tokens, *argc);
		/*STORE TOKENS INTO ARRAY BASED ON ARGC*/
		tokens[*argc] = _strdup(split);
		if (tokens[*argc] == NULL)
		{
			perror("alloc failed: tokens[*argc]");
			handle_memory_allocation_failure(tokens, *argc);
		}
		(*argc)++;
		/*get other fragments*/
		split = _strtok(NULL, " \t\n");
	}
	/*set last value to NULL*/
	tokens[*argc] = NULL;
	return (tokens);/*must be freed manually by user*/
}
