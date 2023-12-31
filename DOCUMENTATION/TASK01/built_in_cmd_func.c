#include "main.h"
/**
 * handle_cd - function that handles changing of directory
 * @args: the cd command to execute
 * Return: 0 for success -1 for error
 */
int handle_cd(char **args)
{
	(void)args;
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
			exit (1);/*invalid*/
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
	(void)args;
	/*set the */
	return (0);
}
