#include "main.h"
/**
 * find_cmd_in_path - finds the command in path from dir_list
 * @cmd: receives the string token from user input
 * @dir_list: receives the linked list of directories
 * Return: returned the path where command is found
 */
char *find_cmd_in_path(char *cmd, dir_node *dir_list)
{
	/**
	 * struct stat: checks for file existence
	 */
	struct stat exist;
	dir_node *current_dir = dir_list;/*a node as curdir to start searching*/
	char *full_path = NULL; /*to hold the full path, and alloc memory*/

	if (cmd == NULL || dir_list == NULL)
		return (NULL);

	/*LOOP THRU dir_list via cur to ret.matchPATH*/
	while (current_dir != NULL)
	{
		/*allocate space based on lenghth of cmd and current_dir*/
		full_path = malloc(_strlen(cmd) +
				_strlen(current_dir->dir) + 2);
		if (full_path == NULL)/*MALLOC RETURN*/
		{
			perror("full_path: mem. alloc failed");
			return (NULL);
		}
		_strcpy(full_path, current_dir->dir);/*cpy currdir 2 fullpath*/
		_strcat(full_path, "/");/*append the forward slash*/
		_strcat(full_path, cmd);/*append the command*/

		if (stat(full_path, &exist) == 0)/*check if command is valid using stat*/
			return (full_path);/*it means path is valid*/

		free(full_path);/*free the full path after return*/
		current_dir = current_dir->next;/*or try to check another dir*/
	}
	return (NULL);
}
/**
 * exec_child_proces - executes the child process
 * @tokens: the array of words to execute
 * @dir_list: the list of directory to look from
 * Return: execution status -1 for error 0 for success
 */
int exec_child_proces(char **tokens, dir_node *dir_list)
{
	char *full_path = NULL;/*to store full path in case*/
	/*checks if a directory was first referenced*/
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
			_fprintf("./hsh: 1: %s: not found\n", tokens[0]);
			exit(127);
		}
	}
}
/**
 * exec_tokens - recieves users' cmd and runs it
 * @tokens: user arguments/tokens to execute
 * @dir_list: a linked list of directories to check from
 * Return: execution status: 0 for success, -1 for failure
 */
int exec_tokens(char **tokens, dir_node *dir_list)
{
	/*create variable for child process*/
	pid_t child;
	int status = 0, ch_process = 0;/*status variable for wait*/

	/*create child process*/
	child = fork();
	if (child == -1)
	{/*handle create process error*/
		perror("Fork failed");
		return (-1);
	}

	if (child == 0)
	{
		ch_process = exec_child_proces(tokens, dir_list);
		if (ch_process == -1)
			return (-1);/*TODO: something can be done here*/
	}
	else
	{
		wait(&status);/*back to parent process*/
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit_status = WEXITSTATUS(status);
	}
	return (0);/*success*/
}
