#include "main.h"
/**
 * getInput - gets input from user
 * @lines_buffer: temp space to store user input
 * @line_len: track size of user input
 * Return: void
 */
ssize_t getInput(char **lines_buffer, size_t *line_len)
{
	ssize_t line_size;

	line_size = getline(lines_buffer, line_len, stdin);
	if ((*lines_buffer)[0] == '#')
	{
		return (-3);
	}
	else if (line_size == -1)
		return (-1);
	else if (line_size == 1 && (*lines_buffer)[0] == '\n')
	{
		return (0);
	}
	else
	{
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
	int i = 0, built_in = 0, run = 1;
	ssize_t rtn_val_input = 0;
	dir_node *dir_list = build_dir_list();/*call the build dir list fxn*/
	int interactive_mode = isatty(STDIN_FILENO);

	while (run)
	{
		if (interactive_mode)
		{
			_printf("$ ");
			fflush(stdout);
		}
		rtn_val_input = getInput(&lines_buffer, &line_len);
		if (rtn_val_input == -3)
			continue;
		if (rtn_val_input == -1)
		{
			run = 0;
			break;
		}
		argc = 0;/*starting point of arg.count*/
		tokens = parse_tokens(lines_buffer, &argc);
		if (argc > 0)
		{
			built_in = get_built_cmd_func(tokens);
			if (built_in == -1)
				exec_tokens(tokens, dir_list);/*CALL EXEC_TOKEN FUNC*/
		}
		for (i = 0; i < argc; i++)
			free(tokens[i]);
		free(tokens);
	}
	free(lines_buffer);
	free_dir_list(dir_list);
	return (exit_status);
}
