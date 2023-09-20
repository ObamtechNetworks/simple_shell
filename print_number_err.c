#include "main.h"
/**
 * convert_to_heX2 - converts a positive integer to its hexadecimal
 * representation in uppercase alphabetic letter
 * @number: positive integer
 *
 * Return: returns the ascii value for the uppercase letter of the hex notation
 */
int convert_to_heX2(unsigned int number)
{
	/* declare variables */
	c_t conversion_table[] = {
		{10, "A"},
		{11, "B"},
		{12, "C"},
		{13, "D"},
		{14, "E"},
		{15, "F"}
	};
	int i, asciiVal;
	char *s, uppercaseChar;

	/* iniitialize variables */
	i = 0;

	/* seek the hexadecimal notation */
	while (conversion_table[i].numConst != number)
		i++;

	s = conversion_table[i].numStr;
	uppercaseChar = *s;

	/* convert to ascii */
	asciiVal = (int)uppercaseChar;

	return (asciiVal);
}
/**
 * convert_to_hex2 - converts a positive integer to its hexadecimal
 * representation in lowercase alphabetic letter
 * @number: positve integer
 *
 * Return: returns the ascii value for the lowercase letter of the hex notation
 */
int convert_to_hex2(unsigned int number)
{
	/* declare variables */
	c_t conversion_table[] = {
		{10, "a"},
		{11, "b"},
		{12, "c"},
		{13, "d"},
		{14, "e"},
		{15, "f"}
	};
	int i, asciiVal;
	char *s, lowercaseChar;

	/* initialize variables */
	i = 0;

	/* seek the hexadecimal notation */
	while (conversion_table[i].numConst != number)
		i++;

	s = conversion_table[i].numStr;
	lowercaseChar = *s;

	/* convert to ascii */
	asciiVal = (int)lowercaseChar;

	return (asciiVal);
}
/**
 * print_base_162 - prints a positive integer in base 16 notation
 * @num: a positive integer
 * @hex_case: the conversion specifier case
 *
 * Return: returns the number of characters printed to standard output
 */
int print_base_162(unsigned int num, char *hex_case)
{
	/* declare variables */
	int r_value, uppercaseAscii, lowercaseAscii;

	/* initialize variables */
	r_value = 0;
	uppercaseAscii = 0;
	lowercaseAscii = 0;


	/* print base 16 notation */
	if (*hex_case == 'X')
	{
		uppercaseAscii = convert_to_heX2(num);
		r_value += _echar(uppercaseAscii);
	}

	if (*hex_case == 'x')
	{
		lowercaseAscii = convert_to_hex2(num);
		r_value += _echar(lowercaseAscii);
	}

	return (r_value);
}
/**
 * print_number2 - function that prints a positive integer in a base notation
 * @digit: a positive integer
 * @base: the base notation in which digit should be printed
 * @hex_case: the conversion specifier case
 *
 * Return: returns the number of characters printed to standard output
 */
int print_number2(unsigned int digit, unsigned int base, char *hex_case)
{
	/* declare variables */
	unsigned int exponent, count, num, number;
	int r_value;

	/* initialize variables */
	count = 0;
	exponent = 1;
	r_value = 0;
	num = digit;

	/* get the count of base in digit */
	while (digit > 0)
	{
		digit = digit / base;
		count++;
	}

	/* calculate its exponent */
	while (count > 1)
	{
		exponent = exponent * base;
		count--;
	}

	/* print the integer */
	while (exponent > 0)
	{
		number = num / exponent;
		if ((number >= 10 && number < 16) && base > 10)
			r_value += print_base_162(number, hex_case);
		else
			r_value += _echar(number + '0');

		num = num - (number * exponent);
		exponent /= base;
	}

	return (r_value);
}
