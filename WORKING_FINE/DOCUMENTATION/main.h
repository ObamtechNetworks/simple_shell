#ifndef MAIN_H
#define MAIN_H

/* C standard library header files */
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdarg.h>
#include <string.h>/*added this...*/

#define BUF_CAPACITY 1024
#define BUF_CLEARING -1
#define EMPTY_STRING "(null)"

/* function prototypes */
int _putchar(int c);
int (*find_format_handlers(const char *format))(va_list arg);
int print_spec_c_match(va_list arg);
int print_spec_d_match(va_list arg);
int print_spec_s_match(va_list arg);
int print_percent(va_list arg);

/*string1.c*/
char *_memcpy(char *dest, char *src, unsigned int n);
char *_memset(char *s, char b, unsigned int n);
void _puts(char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);

/*string2.c*/
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

/*string3.c*/
char *_strncat(char *dest, char *src, int n);
char *_strstr(char *haystack, char *needle);

/*======= SIMPLE SHELL FUNCTIONS =========*/
char **parse_tokens(char *input, int *argc);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/*==================================================================*/

/* Helper functions 1*/
char *convert_to(long int num, int base);
int print_number(unsigned int digit, unsigned int base, char *hex_base);

int _printf(const char *format, ...);

/**
 * struct conversion_table - data structure for storing hex conversion notation
 * @numConst: integer
 * @numStr: associated hex notation
 */
typedef struct conversion_table
{
	unsigned int numConst;
	char *numStr;
} c_t;

/**
 * struct format_handler - Struct token
 * @format_char: the format token
 * @handler_func: The function associated
 */
typedef struct format_handler
{
	char *format_char;
	int (*handler_func)(va_list);

} format_handler;

#endif /* MAIN_H */
