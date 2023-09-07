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
