#include "main.h"

int exit_status = 0;

/**
 * getInput - gets input from user
 * @lines_buffer: temp space to store user input
 * @line_len: track size of user input
 * @prompt: prints prompt per executed input
 * Return: void
 */
ssize_t getInput(char **lines_buffer, size_t *line_len)
{
	ssize_t line_size;

	line_size = getline(lines_buffer, line_len, stdin);
	if (line_size == -1)
	{
		/*printf("encounter\n");*/
		return (-1);
		/*perror("\nExit getline...");*/
		/*exit(EXIT_SUCCESS);*NOTES: might need to utilize rtn valu*/
	}/*if user pass new line, just enter key*/
	else if (line_size == 1 && (*lines_buffer)[0] == '\n')
	{
		/*printf("error 2\n");*/
		return (0);
	}
	else
	{
		/*printf("error 3\n");*/
		return (0);
	}
}
/**
 * main - entry point
 * Return: (0)Success
 */
int main(void)
{
	char *lines_buffer = NULL;
	size_t line_len = 0;
	char **tokens = NULL;
	int argc = 0;
	/*int rtn;*/
	int i = 0, built_in = 0;
	ssize_t rtn_val_input = 0;
	/*initialize dir list from our struct node*/
	dir_node *dir_list = build_dir_list();/*call the build dir list fxn*/
	int run = 1;
	int interactive_mode = isatty(STDIN_FILENO);

	while (run)
	{
		if (interactive_mode)
		{
			printf("$ ");
			fflush(stdout);
		}
		/*get user input and store inside buffer*/
		rtn_val_input = getInput(&lines_buffer, &line_len);
		if (rtn_val_input == -1)
		{
			printf("\n");
			run = 0;
			break;
		}
		/*generate tokens by calling parse_token*/
		argc = 0;/*starting point of arg.count*/
		tokens = parse_tokens(lines_buffer, &argc);
		/*create a process and call command*/
		if (argc > 0)
		{
			built_in = get_built_cmd_func(tokens);
			if (built_in == -1)
				exec_tokens(tokens, dir_list);/*CALL EXEC_TOKEN FUNC*/
			/*if (WEXITSTATUS(rtn))
			{
				exit(127);
			}*/
		}
		/*FREE ALLOC MEMORY FOR TOKENS AND TOK_ARRAY ITSELF*/
		for (i = 0; i < argc; i++)
			free(tokens[i]);
		free(tokens);
	}
	free(lines_buffer);
	/*FREE DIRECTORY LIST*/
	free_dir_list(dir_list);
	return (exit_status);
}
