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

/** STRUCTURE FOR BUILT IN COMMANDS */
/**
 * struct built_in - structure for builtin cmds
 * @cmd_name: the name of the built in command
 * @handler: the function that handles the command
 */
typedef struct built_in
{
	char *cmd_name;
	int (*handler)(char **args);
} built_in;
/** ==== HANDLER FUNCTIONS FOR BUILT IN CMDS **/
int get_built_cmd_func(char **args);
int handle_cd(char **args);
int handle_exit(char **args);
int handle_env(char **args);

/*SUPPLEMENTARY FUNCTIONS */
long int _strtol(const char *nptr, char **endptr);
/** STRUCTURE FOR LINKED LIST OF DIRECTORIES*/
/**
 * struct dir_node - structure for directory of linked lists
 * @dir: the directory string
 * @next: the pointer to the next node in the list
 */
typedef struct dir_node
{
	char *dir;
	struct dir_node *next;
} dir_node;

/** LINKED LIST FUNCTIONS PROTOYPES */
dir_node *create_dir_node(char *dir);/*creates a new dir node*/
void add_directory(dir_node **head, char *dir);
dir_node *build_dir_list(void);
void free_dir_list(dir_node *head);
char *find_cmd_in_path(char *cmd, dir_node *dir_list);

/** ENVIRON VARIABLE */
extern char **environ;
/** GET ENV FUNCTION */
char *_getenv(const char *name);

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
int exec_tokens(char **tokens, dir_node *dir_list);
char *_strtok(char *str, const char *delim);
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
