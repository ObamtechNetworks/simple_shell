#include "main.h"
/**
 * getInput - gets input from user
 * @lines_buffer: temp space to store user input
 * @line_len: track size of user input
 * @prompt: prints prompt per executed input
 * Return: void
 */
void getInput(char **lines_buffer, size_t *line_len, const char *prompt)
{
	ssize_t line_size;

	printf("%s", prompt);
	line_size = getline(lines_buffer, line_len, stdin);
	if (line_size == -1)
	{
		perror("\nExit getline...");
		exit(EXIT_FAILURE);/*NOTES: might need to utilize rtn valu*/
	}
}
/**
 * main - entry point
 * Return: (0)Success
 */
int main(void)
{
	char *prompt, *lines_buffer;
	size_t line_len = 0;
	char **tokens;
	int argc;
	int i;
	/*some new variables above*/
	lines_buffer = NULL;
	prompt = "Prompt$ ";

	while (1)
	{
		/*get user input and store inside buffer*/
		getInput(&lines_buffer, &line_len, prompt);
		/*generate tokens by calling parse_token*/
		argc = 0;/*starting point of arg.count*/
		tokens = parse_tokens(lines_buffer, &argc);

		/*create a process and call command*/

		/*FREE ALLOC MEMORY FOR TOKENS AND TOK_ARRAY ITSELF*/
		for (i = 0; i < argc; i++)
			free(tokens[i]);
		free(tokens);
	}
	free(lines_buffer);

	return (0);
}
