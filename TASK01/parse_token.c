#include "main.h"

/**
 * parse_tokens - breaks inputs into array of tokens/words
 * @input: arguments from user
 * @argc: keeps track of number of arguments
 * Return: an array of tokens being parsed
 */
char **parse_tokens(char *input, int *argc)
{
	/*Parse the inputs into tokens and store in an array*/
	char **tokens = NULL;/*the eventual array to return*/
	char *split;/*keep track of each pieces*/

	/*call strtok to split input based on delimiters*/
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
		{
			perror("Token allocation failed");
			exit(EXIT_FAILURE);/** NOTES we may need return values*/
		}
		/*STORE TOKENS INTO ARRAY BASED ON ARGC*/
		tokens[*argc] = _strdup(split);
		(*argc)++;
		/*get other fragments*/
		split = strtok(NULL, " \t\n");
	}
	/*set last value to NULL*/
	tokens[*argc] = NULL;
	return (tokens);/*must be freed manually by user*/
}

