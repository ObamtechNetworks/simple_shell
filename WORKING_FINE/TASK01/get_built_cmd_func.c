#include "main.h"
/**
 * get_built_cmd_func - gets the respective function based on builtin cmd
 * @args: the built in command to point or invoke its equivalent function
 * Return: returns the function, -1 for error
 */
int get_built_cmd_func(char **args)
{
	/*populate the arrays of builtin commands strings*/
	built_in cmd_array[] = {
		{"exit", handle_exit},
		{"cd", handle_cd},
		{"env", handle_env}
	};
	int i = 0;
	int size = sizeof(cmd_array) / sizeof(cmd_array[0]);

	/** loop through the struct array to find matching function*/
	for (i = 0; i < size; i++)
		if (_strcmp(args[0], cmd_array[i].cmd_name) == 0)
			return (cmd_array[i].handler(args));
	/*else return -1 for error handling*/
	return (-1);
}
