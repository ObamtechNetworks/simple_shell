#include "main.h"
/**
 * handle_cd - function that handles changing of directory
 * @args: the cd command to execute
 * Return: 0 for success -1 for error
 */
int handle_cd(char **args)
{
	char *prev_dir = NULL;/*address of prev working directory*/
	char *cur_w_dir = getcwd(NULL, 0);/*gets cur_w dir, alloc mem*/
	char *home_dir = _getenv("HOME");/*to store user's home dir str*/

	if (home_dir == NULL)
	{
		perror("cd");
		return (-1);
	}
	if (cur_w_dir == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	if (prev_dir != NULL)
		free(prev_dir);/*free prev_dir if allocated before*/
	prev_dir = _strdup(cur_w_dir);
	if (prev_dir == NULL)
	{
		perror("mem alloc prev dir");
		free(cur_w_dir);
		return (-1);
	}
	free(cur_w_dir);/*now free alloc frm getcwd*/
	if (args[1] == NULL)/*operate on arguments if exists*/
	{
		if (chdir(home_dir) != 0)
		{
			perror("cd");
			return (-1);
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (prev_dir == NULL)
		{
			_fprintf("%s: 1: cd: can't cd to ", args[0]);
			return (-1);
		}
		if (chdir(prev_dir) != 0)
		{
			perror("cd");
			return (-1);
		}
	}
	else
	{/*change to user's direct with space for err check*/
		if (chdir(args[1]) != 0)
		{
			_fprintf("%s: 1: cd: can't cd to ", args[0]);
			errno = EACCES;
			return (0);
		}
	}
	/*at the end free mem alloc for prev_dir*/
	if (prev_dir != NULL)
		free(prev_dir);
	return (0);
}
/**
 * handle_exit - function to handle the exiting of the shell
 * @args: the exit command to execute
 * Return: 0 success
 */
int handle_exit(char **args)
{
	long exit_str = 0;/*convert exit str to NUM*/
	char *endptr = NULL;/*to store occurrence of char*/
	/*execute arguments if they exists */
	if (args[1] != NULL)
	{
		/*convert the string as an integer*/
		exit_str = _strtol(args[1], &endptr);
		if (endptr == NULL || *endptr != '\0')
		{
			perror("invalid exit status");
			exit(1);/*invalid*/
		}
		/*return the exit status based on parsed string*/
		/*exit status must be between the range*/
		if (exit_str >= 0 && exit_str <= 255)
			exit((int)exit_str);
		else
		{
			/*if exit status is beyond range, print err to stderr*/
			perror("out of range");
			exit(1);/*out of range*/
		}
	}
	/*else if no argument, exit with exit status of 0*/
	exit(0);
}
/**
 * handle_env - function that handles shell environment variable
 * @args: the env variable command
 * Return: 0 success
 */
int handle_env(char **args)
{
	/*local variable*/
	char **env = environ;

	/*check if there are no arguments*/
	if (args != NULL)
	{
		for (; *env != NULL; env++)
			_printf("%s\n", *env);
	}
	/*else, loop through variable environ to print each value out*/
	return (0);
}
