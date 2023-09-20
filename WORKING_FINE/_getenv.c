#include "main.h"
/**
 * _getenv - gets an environment variable without using getenv
 * @name: environment variable name
 * Return: returns the address of the environmnet variable
 */
char *_getenv(const char *name)
{
	/*variable to return found env. varaible value*/
	char *var_isFound = NULL;

	/*STORE ENVIRON IN A POINTER VARIABLE */
	char **search_env = environ;
	/*LOOP THROUGH THE GLOBAL ENV. VARIABLE*/
	for (; *search_env; search_env++)
	{
		/*COMPARE THE NAME OF var we looking for wt, global environ*/
		if (strncmp(name, *search_env, strlen(name)) == 0)
		{
			/*mv ptr pass the name & equalto of key to the val*/
			var_isFound = *search_env + strlen(name) + 1;/*1 byte for NULL TERM*/
			return (var_isFound);
		}
	}
	return (NULL);/*if nothing is eventually found*/
}
