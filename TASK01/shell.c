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
	}/*if user pass new line, just enter key*/
	else if (line_size == 1 && (*lines_buffer)[0] == '\n')
		return;
}
/**
 * main - entry point
 * Return: (0)Success
 */
int main(void)
{
	char *prompt = NULL, *lines_buffer = NULL;
	size_t line_len = 0;
	char **tokens = NULL;
	int argc = 0;
	int i = 0;
	/*initialize dir list from our struct node*/
	dir_node *dir_list = build_dir_list();/*call the build dir list fxn*/
	/*some new variables above*/
	prompt = "Prompt$ ";

	while (1)
	{
		/*get user input and store inside buffer*/
		getInput(&lines_buffer, &line_len, prompt);
		/*generate tokens by calling parse_token*/
		argc = 0;/*starting point of arg.count*/
		tokens = parse_tokens(lines_buffer, &argc);
		/*create a process and call command*/
		if (argc > 0)
			exec_tokens(tokens, dir_list);/*CALL EXEC_TOKEN FUNC*/
		/*FREE ALLOC MEMORY FOR TOKENS AND TOK_ARRAY ITSELF*/
		for (i = 0; i < argc; i++)
			free(tokens[i]);
		free(tokens);
	}
	free(lines_buffer);
	/*FREE DIRECTORY LIST*/
	free_dir_list(dir_list);
	return (0);
}
