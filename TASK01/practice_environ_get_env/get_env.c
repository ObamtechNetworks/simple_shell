#include "main.h"

/**
 * _getenv - gets an environment variable without using getenv
 * @name: environment variable name
 * Return: returns the address of the environmnet variable
 */
char *_getenv(const char *name)
{
	/*we can do this by using the global env. variables*/
	/*the logic would be to loop through the env.vars*/
	/*in the process of loop, we compare the name of the
	 * specifi variable we are looking for by the current env variable
	 * however focussing on the name of the variable we looking for,so strncmp*/
	/*if found, we then return that string (that is the valueof that variable */

	/*variable to return found env. varaible value*/
	char *var_isFound;

	/*STORE ENVIRON IN A POINTER VARIABLE */
	char **search_env = environ;
	/*LOOP THROUGH THE GLOBAL ENV. VARIABLE*/
	for (; *search_env; search_env++)
	{
		/*COMPARE THE NAME OF var we looking for wt, global environ*/
		if (strncmp(name, *search_env, strlen(name)) == 0)
		{
			/*move pointer pass the name & equalto of the variable to the value*/
			var_isFound = *search_env + strlen(name) + 1;/*1 byte for NULL TERM*/
			return (var_isFound);
		}
	}
	return (NULL);/*if nothing is eventually found*/
}

/**
 * main - get a variable environment
 * Return: 0
 */
int main (void)
{
	char *var_key = _getenv("PATH");

	printf("%s\n", var_key);

	return (0);
}
