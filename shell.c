#include "main.h"

void getInput(char **lines_buffer, size_t *line_len, const char *prompt)
{
	ssize_t line_size;

	printf("%s", prompt);
	line_size = getline(lines_buffer, line_len, stdin);
	if (line_size == -1)
	{
		perror("\nExit getline...");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	char *prompt, *lines_buffer;
	size_t line_len = 0;

	lines_buffer = NULL;
	prompt = "Prompt$ ";

	while (1)
	{	
		getInput(&lines_buffer, &line_len, prompt);
	}
	free(lines_buffer);

	return (0);
}
