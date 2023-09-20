#include "main.h"
/**
 * _setenv - addes an environment variable to the env list
 * @name: the name of the variable
 * @value: the value of the variable
 * @overwrite: overwrites variable if true
 * Return: 0 on success -1 for error
 */
int _setenv(char *name, char *value, int overwrite)
{
	char **env = environ;/*get a variable to store the glob env. variable*/
	char *new_var = NULL;/*new environment var str*/
	int env_len = 0, i = 0;/*LENGTH OF NEW ENV VAR*/
	char **new_env = NULL;
	char *name_ptr = name, *val_ptr = value;
	/*edge cases, NULL, length 0 or contains =*/
	if (name_ptr == NULL || (_strlen(name_ptr) == 0) || (_strchr(name_ptr, '=') != NULL))
		return (-1);
	/*alloc space for new env var based on name length and val*/
	new_var = malloc(_strlen(name_ptr) + _strlen(val_ptr) + 2);/*2byte: '='& NULL*/
	if (new_var == NULL)
		return (-1);
	_strcpy(new_var, name_ptr);/*copy name into new variable*/
	_strcat(new_var, "=");/*appends = sign*/
	_strcat(new_var, val_ptr);/*appends value*/
	/*loop through glob. env to search/comp. if variable exists*/
	while (*env != NULL)
	{
		if (overwrite)/*found, make decision based on overwrite state*/
		{
			free(*env);/*frees the old env variable*/
			*env = new_var;/*adds the new env variable*/
			return (0);
		}
		else
		{
			free(new_var);/*nothing's found free all that we allocated*/
			return (0);
		}
		env++;/*mv env*/
	}
	while (*env)/*get len of glob env variable*/
	{
		env_len++;
		env++;
	}
	new_env = malloc((env_len + 2) * sizeof(char *));/*CREATE NEWEV*/
	if (new_env == NULL)
	{
		free(new_var);/*our previously allocated env var*/
		return (-1);
	}
	for (i = 0; i < env_len; i++)
		new_env[i] = _strdup(env[i]);/*copy invidual oldenv to new env*/
	new_env[env_len] = new_var;/*add new env to last position and null*/
	new_env[env_len + 1] = NULL;
	/*update new  environ pointer to new environment*/
	environ = new_env;
	return (0);
}
