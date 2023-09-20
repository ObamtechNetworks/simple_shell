#include "main.h"
/**
 * _isspace - a function that checks if a char is a space
 * @c: the char to check
 * Return: 1 for true, 0 for false
 */
int _isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
			|| c == '\f' || c == '\v')
		return (1);
	return (0);
}
/**
 * _isdigit - checks if a har is a digit
 * @c: the char to check
 * Return: 1 for true, 0 for false
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * _isalpha - checks if a character is alphabet
 * @c: the character to check
 * Return: 1 for true 0 for false
 */
int _isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/**
 * _tolower - converts a character to lowercase
 * @c: the characer to convert
 * Return: converted character
 */
char _tolower(char c)
{
	/*convert to lowercase equiv if it's an uppercase*/
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);/*return c as is*/
}
/**
 * _strtol - a custom strtol function that conv. str to long integers
 * @nptr: the  portion of the string to convert
 * @endptr: ptr to arr of string, used to capture address where conv. stopped
 * Return: the converted value
 */
long int _strtol(const char *nptr, char **endptr)
{
	long output = 0;/*initialize local variables*/
	int sign = 1, digit;/*state var to track sign*/
	const char *cur_nptr = nptr;/*track cur pos of nptr*/
	int base = 10;
	/*chck for whitspaces and skip*/
	while (_isspace(*cur_nptr))
		cur_nptr++;/*keep skipping to next char*/
	/*verify if there is sign char*/
	if (*cur_nptr == '-' || *cur_nptr == '+')
	{
		if (*cur_nptr == '-')
			sign = -1;/*set the sign*/
		cur_nptr++;/*check next*/
	}
	while (1)/*convert string to long integer*/
	{
		if (_isdigit(*cur_nptr))
			digit = *cur_nptr - '0';
		else if (_isalpha(*cur_nptr))
			digit = _tolower(*cur_nptr) - 'a' + 10;
		else
			break;/*end of number*/
		if (digit >= base)
			break;/*invalid digit for cur base*/
		if (output > (LONG_MAX - digit) / base)/*chk overflwo*/
		{
			if (endptr != NULL)
				*endptr = (char *)cur_nptr;
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		output = output * base + digit;
		cur_nptr++;
	}
	if (endptr != NULL)/*set endptr val*/
		*endptr = (char *)cur_nptr;
	return (output * sign);
}
