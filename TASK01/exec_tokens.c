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
		perror("Invalid input, cmd or dir_List is NULL");
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
 * exec_tokens - recieves users' cmd and runs it
 * @tokens: user arguments/tokens to execute
 * Return: execution status: 0 for success, -1 for failure
 */
int exec_tokens(char **tokens, dir_node *dir_list)
{
	char *full_path = NULL; /*variable to hold full path from dirlist*/
	/*create variable for child process*/
	pid_t child;
	int status = 0;/*status variable for wait*/
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
				/*call execve command with environ variable &fullpath*/
				execve(full_path, tokens, environ);
				/*code below will only run when execve failed*/
				perror("execve failed");
				free(full_path);/*free full path frm find_cmd*/
				return (-1);/*error code*/
			}
			else
			{
				free(full_path);
				printf("path not found\n");
				/*(_printf("command not found: %s\n", tokens[0]);*/
				/*exit(EXIT_FAILURE);*/
			}
		}
	}
	else
	{
		wait(&status);/*back to parent process*/
		/*if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			_printf("Child process exited with error: %d\n",
					WEXITSTATUS(status));
			return (-1);
		}*/
	}
	return (0);/*success*/
}
