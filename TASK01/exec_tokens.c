#include "main.h"
/**
 * exec_tokens - recieves users' cmd and runs it
 * @tokens: user arguments/tokens to execute
 * Return: execution status: 0 for success, -1 for failure
 */
int exec_tokens(char **tokens)
{
	/*create variable for child process*/
	pid_t child;
	int status;/*status variable for wait*/
	/*create child process*/
	child = fork();
	if (child == -1)
	{
		/*handle create process error*/
		perror("Fork failed");
		return (-1);
	}
	if (child == 0)
	{
		/*call execve command with environ variable*/
		if (execve(tokens[0], tokens, environ) == -1)
		{
			perror("execve failed");
			/*return (-1);*returns error code*/
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);/*back to parent process*/
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			printf("Child process exited with error: %d\n",
					WEXITSTATUS(status));
			return (-1);
		}
	}
	return (0);/*success*/
}
