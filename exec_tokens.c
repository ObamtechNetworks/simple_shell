#include "main.h"

/**
 * find_cmd_in_path - finds the command in path from dir_list
 * @cmd: receives the string token from user input
 * @dir_list: receives the linked list of directories
 * Return: returned the path where command is found
 */
char *find_cmd_in_path(char *cmd, dir_node *dir_list)
{
	struct stat exist;/*to chck file existence*/
	/*create a node as current dir to start searching from*/
	dir_node *current_dir = dir_list;
	/*create a string to hold the full path, and alloc memory*/
	char *full_path = NULL;

	if (cmd == NULL || dir_list == NULL)
	{
		return (NULL);
	}
	/*LOOP THROUGH THE dir_list via current_dir*/
	while (current_dir != NULL)
	{
		/*allocate space based on lenghth of cmd and current_dir*/
		full_path = malloc(_strlen(cmd) +
				_strlen(current_dir->dir) + 2);
		/*MALLOC RETURN*/
		if (full_path == NULL)
		{
			perror("full_path: mem. alloc failed");
			return (NULL);
		}
		_strcpy(full_path, current_dir->dir);/*cpy currdir 2 fullpath*/
		_strcat(full_path, "/");/*append the forward slash*/
		_strcat(full_path, cmd);/*append the command*/
		/*check if command is valid using stat*/
		if (stat(full_path, &exist) == 0)
		{
			return (full_path);/*it means path is valid*/
		}
		free(full_path);/*free the full path after return*/
		/*or try to check another dir*/
		current_dir = current_dir->next;
	}
	return (NULL);
}

/**
 * execute_child_process - executes the child process
 * @tokens: user arguments/tokens to execute
 * @dir_list: linked list of directories
 * Return: execution status: 0 for success, -1 for failure
 */
int execute_child_process(char **tokens, dir_node *dir_list)
{
	char *full_path = NULL;

	if (_strchr(tokens[0], '/') != NULL)
	{
		execve(tokens[0], tokens, environ);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		full_path = find_cmd_in_path(tokens[0], dir_list);
		if (full_path != NULL)
		{
			execve(full_path, tokens, environ);
			perror("execve failed");
			free(full_path);
			return (-1);
		}
		else
		{
			free(full_path);
			_fprintf("./hsh: 1: %s: not found\n", tokens[0]);
			exit(127);
		}
	}
}

/**
 * exec_tokens - receives users' cmd and runs it
 * @tokens: user arguments/tokens to execute
 * @dir_list: linked list of directories
 * Return: execution status: 0 for success, -1 for failure
 */
int exec_tokens(char **tokens, dir_node *dir_list)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == -1)
	{
		perror("Fork failed");
		return (-1);
	}

	if (child == 0)
	{
		execute_child_process(tokens, dir_list);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			exit_status = WEXITSTATUS(status);
		}
	}

	return (0);
}
